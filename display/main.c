//
// Created by lukas on 09.04.2025.
//

#include "main.h"

#include <stdio.h>
#include <math.h>

#include "../board/empty-cell.h"

void printSudokuCell(int number) {
    if (number == EMPTY_CELL_SUDOKU) {
        printf(" %2c ", '.');
        return;
    }

    printf(" %2d ", number);
}

void printSudokuRow(int **sudoku, int row, BoardSizes boardSize) {
    const int squareSize = (int) sqrt(boardSize);

    for (int j = 0; j < boardSize; j++) {
        if (j % squareSize == 0) {
            printf("|");
        }


        printSudokuCell(sudoku[row][j]);
    }

    printf("|\n");
}

void printSudokuHorizontalBorder(BoardSizes boardSize) {
    const int squareSize = (int) sqrt(boardSize);

    for (int j = 0; j < boardSize; j++) {
        if (j % squareSize == 0) {
            printf("+");
        }
        printf("----");
    }
    printf("+\n");
}

void printSudoku(int **sudoku, BoardSizes boardSize) {
    const int squareSize = (int) sqrt(boardSize);

    for (int i = 0; i < boardSize; i++) {
        if (i % squareSize == 0) {
            printSudokuHorizontalBorder(boardSize);
        }

        printSudokuRow(sudoku, i, boardSize);
    }

    printSudokuHorizontalBorder(boardSize);
};