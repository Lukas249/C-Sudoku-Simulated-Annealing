//
// Created by lukas on 17.04.2025.
//

#include "main.h"
#include "../display/main.h"

#include "../validate/main.h"
#include <stdlib.h>
#include <math.h>

#include "../board/countEmptyCells.h"
#include "../board/empty-cell.h"
#include "../board/generate/generateAllBoardPositions.h"
#include "../board/generate/generateEmptyCellPositions.h"

int* possibleNumbersSudoku(int **sudoku, BoardSizes boardSize, int row, int column) {
    int *numbers = malloc(sizeof(int) * (boardSize + 1));

    for (int i = 1; i <= boardSize; i++) {
        numbers[i] = true;
    }

    numbers[0] = false;

    // Mark each number that appears in row or column 'i' as 'false'
    for (int i = 0; i < boardSize; i++) {
        numbers[sudoku[row][i]] = false;
        numbers[sudoku[i][column]] = false;
    }

    int squareSize = (int) sqrt(boardSize);
    int row_start = row / squareSize * squareSize;
    int column_start = column / squareSize * squareSize;

    // Mark each number that appears in the MxM square containing the given 'row' and 'column' as 'false'
    for (int i = row_start; i < row_start + squareSize; i++) {
        for (int j = column_start; j < column_start + squareSize; j++) {
            int number = sudoku[i][j];

            if (number == EMPTY_CELL_SUDOKU) continue;

            numbers[number] = false;
        }
    }

    int possibleNumbersCount = 0;

    // Count all possible numbers at the given 'row' and 'column'
    // excluding the original value at that position
    for (int i = 1; i <= boardSize; i++) {
        if (!numbers[i]) {
            continue;
        }

        possibleNumbersCount++;
    }

    // The first element (index 0) stores the length. The rest are the valid numbers.
    int *possibleNumbersArray = malloc((possibleNumbersCount + 1) * sizeof(int));

    possibleNumbersArray[0] = possibleNumbersCount;

    int *pointer = possibleNumbersArray + 1;

    // Add all possible numbers at the given 'row' and 'column' to a new array
    for (int i = 1; i <= boardSize; i++) {
        if (!numbers[i]) {
            continue;
        }

        *pointer = i;
        pointer++;
    }

    free(numbers);

    return possibleNumbersArray;
}

bool isSudokuSolvableHelper(int **sudoku, BoardSizes boardSize, int **positions, int lastPositionsIndex) {
    if (lastPositionsIndex < 0) return true;

    int *position = positions[lastPositionsIndex];

    int *possibleNumbers = possibleNumbersSudoku(sudoku, boardSize, position[0], position[1]);

    for (int i = 1; i <= possibleNumbers[0]; i++) {
        sudoku[position[0]][position[1]] = possibleNumbers[i];

        if (isSudokuSolvableHelper(sudoku, boardSize, positions, lastPositionsIndex - 1)) {
            sudoku[position[0]][position[1]] = EMPTY_CELL_SUDOKU;
            free(possibleNumbers);
            return true;
        }

        sudoku[position[0]][position[1]] = EMPTY_CELL_SUDOKU;
    }

    free(possibleNumbers);

    return false;
}

bool isSudokuSolvable(int **sudoku, BoardSizes boardSize) {
    int emptyCellsCount = countEmptyCells(sudoku, boardSize);

    int **positions = generateEmptyCellPositions(sudoku, boardSize, emptyCellsCount);

    bool result = isSudokuSolvableHelper(sudoku, boardSize, positions, emptyCellsCount - 1);

    freeEmptyCellPositions(positions, emptyCellsCount);

    return result;
}

bool solveSudokuHelper(int **sudoku, BoardSizes boardSize, int **positions, int lastPositionsIndex) {
    if (lastPositionsIndex < 0) return true;

    int *position = positions[lastPositionsIndex];

    int *possibleNumbers = possibleNumbersSudoku(sudoku, boardSize, position[0], position[1]);

    for (int i = 1; i <= possibleNumbers[0]; i++) {
        sudoku[position[0]][position[1]] = possibleNumbers[i];

        if (solveSudokuHelper(sudoku, boardSize, positions, lastPositionsIndex - 1)) {
            free(possibleNumbers);
            return true;
        }

        sudoku[position[0]][position[1]] = EMPTY_CELL_SUDOKU;
    }

    free(possibleNumbers);

    return false;
}

void solveSudoku(int **sudoku, BoardSizes boardSize) {
    int emptyCellsCount = countEmptyCells(sudoku, boardSize);

    int **positions = generateEmptyCellPositions(sudoku, boardSize, emptyCellsCount);

    solveSudokuHelper(sudoku, boardSize, positions, emptyCellsCount - 1);

    freeEmptyCellPositions(positions, emptyCellsCount);
}