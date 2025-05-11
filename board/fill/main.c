//
// Created by lukas on 17.04.2025.
//

#include "main.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "empty-cell.h"
#include "../../helpers/generate-array.h"
#include "../../helpers/get-random-number.h"

void fillSudokuSquare(int **sudoku, BoardSizes boardSize, int squareIndex) {
    const int squareSize = (int) sqrt(boardSize);

    int numbersCount = boardSize;
    int* numbers = generateArray(1, boardSize);

    int squareRowStart = squareIndex / squareSize * squareSize;
    int squareColumnStart = squareIndex % squareSize * squareSize;

    int squareRowEnd = squareRowStart + squareSize;
    int squareColumnEnd = squareColumnStart + squareSize;

    // remove all numbers that are already in the n x n square
    for (int i = squareRowStart; i < squareRowEnd; i++) {
        for (int j = squareColumnStart; j < squareColumnEnd; j++) {
            const int len = numbersCount;

            for (int k = 0; k < numbersCount && len == numbersCount; k++) {
                if (sudoku[i][j] != numbers[k]) continue;

                numbers[k] = numbers[numbersCount - 1];
                numbersCount--;
            }
        }
    }

    // filling the n x n square with the remaining numbers in a random order
    for (int i = squareRowStart; i < squareRowEnd && numbersCount > 0; i++) {
        for (int j = squareColumnStart; j < squareColumnEnd && numbersCount > 0; j++) {
            if (sudoku[i][j] != EMPTY_CELL_SUDOKU) continue;

            int index = getRandomNumber(0, numbersCount - 1);
            sudoku[i][j] = numbers[index];
            numbers[index] = numbers[numbersCount - 1];
            numbersCount--;
        }
    }

    free(numbers);
}


