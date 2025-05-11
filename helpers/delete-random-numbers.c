//
// Created by lukas on 17.04.2025.
//

#include <stdio.h>
#include <stdlib.h>

#include "get-random-number.h"
#include "../board/empty-cell.h"
#include "../board/generate/generateAllBoardPositions.h"
#include "../solver/main.h"

void deleteRandomNumbers(int **sudoku, BoardSizes boardSize, int difficultyLevel, int maxDeleteNumbers) {
    int positionsLength = boardSize * boardSize;

    int **positions = generateAllBoardPositions(boardSize);

    // For each position, check if it can be removed
    // while ensuring a unique solution and respecting the difficulty limit
    for (int i = positionsLength - 1; i >= 0 && maxDeleteNumbers > 0; i--) {
        int positionIndex = getRandomNumber(0, i);

        bool oneSolution = true;

        int row = positions[positionIndex][0];
        int column = positions[positionIndex][1];

        int *possibleNumbers = possibleNumbersSudoku(sudoku, boardSize, row, column);

        if (possibleNumbers[0] + 1 > difficultyLevel) {
            free(possibleNumbers);
            continue;
        }

        int number = sudoku[row][column];

        // For each possible number (other than the original)
        // check if it could create a second solution making the Sudoku invalid
        for (int j = 1; j <= possibleNumbers[0] && oneSolution; j++) {
            sudoku[row][column] = possibleNumbers[j];

            if (isSudokuSolvable(sudoku, boardSize)) {
                oneSolution = false;
                sudoku[row][column] = number;
            }
        }

        if (oneSolution) {
            maxDeleteNumbers--;
            sudoku[row][column] = EMPTY_CELL_SUDOKU;
        }

        free(possibleNumbers);

        free(positions[positionIndex]);

        positions[positionIndex] = positions[i];
    }

    free(positions);
}
