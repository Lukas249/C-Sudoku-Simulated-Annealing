#include "main.h"

#include <stdlib.h>
#include <time.h>
#include "display/main.h"
#include "fill/main.h"
#include "generate/main.h"

#include <stdbool.h>
#include <stdio.h>
#include <tgmath.h>

#include "empty-cell.h"
#include "fill-array.h"
#include "get-random-number.h"
#include "board-sizes/board-sizes.h"

#include "create/main.h"

bool **sudokuFrozenValues(int **sudoku, BoardSizes boardSize) {
    bool **frozenValues = malloc(sizeof(bool*) * boardSize);

    for (int i = 0; i < boardSize; i++) {
        frozenValues[i] = malloc(sizeof(int) * boardSize);

        for (int j = 0; j < boardSize; j++) {
            frozenValues[i][j] = sudoku[i][j] == EMPTY_CELL_SUDOKU ? false : true;
        }
    }

    return frozenValues;
}

void freeSudokuFrozenValues(bool **frozenValues, BoardSizes boardSize) {
    for (int i = 0; i < boardSize; i++) {
        free(frozenValues[i]);
    }

    free(frozenValues);
}

int calculatePenaltySA(int **sudoku, BoardSizes boardSize) {

    int penalty = 0;

    for (int i = 0; i < boardSize; i++) {
        bool numbersRow[boardSize + 1];
        bool numbersColumn[boardSize + 1];

        fillArray(numbersRow, boardSize + 1, false);
        fillArray(numbersColumn, boardSize + 1, false);

        for (int j = 0; j < boardSize; j++) {
            if (numbersRow[sudoku[i][j]]) {
                penalty++;
            }

            if (numbersColumn[sudoku[j][i]]) {
                penalty++;
            }

            numbersRow[sudoku[i][j]] = true;
            numbersColumn[sudoku[j][i]] = true;
        }
    }

    return penalty;
}

int **generateNeighborSA(int **sudoku, bool **frozenValues, BoardSizes boardSize) {
    int **sudokuNeighbor = malloc(sizeof(int*) * boardSize);

    for (int i = 0; i < boardSize; i++) {
        sudokuNeighbor[i] = malloc(sizeof(int) * boardSize);

        for (int j = 0; j < boardSize; j++) {
            sudokuNeighbor[i][j] = sudoku[i][j];
        }
    }

    int randomSquareIndex = getRandomNumber(0, boardSize - 1);
    int squareSize = sqrt(boardSize);

    int squareRowStart = randomSquareIndex / squareSize * squareSize;
    int squareRowEnd = squareRowStart + squareSize;

    int squareColumnStart = randomSquareIndex % squareSize * squareSize;
    int squareColumnEnd = squareColumnStart + squareSize;

    int countUnfrozenValues = 0;

    for (int i = squareRowStart; i < squareRowEnd; i++) {
        for (int j = squareColumnStart; j < squareColumnEnd; j++) {
            if (frozenValues[i][j]) {
                continue;
            }

            countUnfrozenValues++;
        }
    }

    int **unfrozenPositions = malloc(sizeof(int*) * countUnfrozenValues);
    int unfrozenPosition = 0;

    for (int i = squareRowStart; i < squareRowEnd; i++) {
        for (int j = squareColumnStart; j < squareColumnEnd; j++) {
            if (frozenValues[i][j]) {
                continue;
            }

            unfrozenPositions[unfrozenPosition] = malloc(sizeof(int) * 2);
            unfrozenPositions[unfrozenPosition][0] = i;
            unfrozenPositions[unfrozenPosition][1] = j;

            unfrozenPosition++;
        }
    }

    if (countUnfrozenValues >= 2) {
        int randomUnfrozenIndex1 = getRandomNumber(0, countUnfrozenValues - 1);
        int randomUnfrozenIndex2 = getRandomNumber(0, countUnfrozenValues - 2);

        if (randomUnfrozenIndex1 == randomUnfrozenIndex2) {
            randomUnfrozenIndex2++;
        }

        const int *pos1 = unfrozenPositions[randomUnfrozenIndex1];
        const int *pos2 = unfrozenPositions[randomUnfrozenIndex2];

        int value = sudokuNeighbor[pos1[0]][pos1[1]];

        sudokuNeighbor[pos1[0]][pos1[1]] = sudokuNeighbor[pos2[0]][pos2[1]];
        sudokuNeighbor[pos2[0]][pos2[1]] = value;
    }

    for (int i = 0; i < countUnfrozenValues; i++) {
        free(unfrozenPositions[i]);
    }

    free(unfrozenPositions);

    return sudokuNeighbor;
}

bool acceptanceFunctionSA(const double T, const double deltaE) {
    if (deltaE < 0) {
        return true;
    }

    double r = (double)rand() / RAND_MAX;

    if (r < exp(-(double)deltaE / T)) {
        return true;
    }

    return false;
}

void runSudokuSA(int **sudoku, BoardSizes boardSize, bool **frozenValues, const double startT, const double endT, const double alpha, const int maxIterations) {
    double T = startT;

    int currentE = calculatePenaltySA(sudoku, boardSize);

    SudokuAnnealingState state = {sudoku, currentE, currentE};

    int iteration = 1;

    while (T > endT && iteration <= maxIterations && state.currentE != 0) {
        int **neighbor = generateNeighborSA(state.sudoku, frozenValues, boardSize);

        const int E_neighbor = calculatePenaltySA(neighbor, boardSize);

        const int deltaE = E_neighbor - state.currentE;

        if (acceptanceFunctionSA(T, deltaE)) {
            freeSudoku(state.sudoku, boardSize);
            state.sudoku = neighbor;
            state.currentE = E_neighbor;
            state.bestE = E_neighbor < state.bestE ? E_neighbor : state.bestE;
        } else {
            freeSudoku(neighbor, boardSize);
        }

        if (iteration % 1000 == 0) printf("Iteration: %d, Penalty: %d, Minimum Global Penalty: %d\n", iteration, state.currentE, state.bestE);

        T *= alpha;

        iteration++;
    }

    if (state.currentE == 0) {
        printf("Found solution!\n");
    } else {
        printf("Did not find solution!\n");
    }

    printSudoku(state.sudoku, boardSize);

    printf("Current Energy=%d, Minimum Global Energy=%d\n",
          state.currentE, state.bestE);

    freeSudoku(state.sudoku, boardSize);
    freeSudokuFrozenValues(frozenValues, boardSize);
}

int main(void) {
    srand(time(NULL));

    BoardSizes boardSize = MEDIUM_BOARD;

    int **sudoku = generateSolvableSudoku(boardSize, 3);

    printf("Initial sudoku to solve\n");
    printSudoku(sudoku, boardSize);

    bool **frozenValues = sudokuFrozenValues(sudoku, boardSize);

    for (int i = 0; i < boardSize; i++) {
        fillSudokuSquare(sudoku, boardSize, i);
    }

    printf("Initial sudoku with random numbers\n");
    printSudoku(sudoku, boardSize);

    // SA Algorithm init
    double startT = 1000;
    double alpha = 0.99999;
    double endT = 0.01;
    int maxIterations = 1200000;

    runSudokuSA(sudoku, boardSize, frozenValues, startT, endT, alpha, maxIterations);

    return 0;
}
