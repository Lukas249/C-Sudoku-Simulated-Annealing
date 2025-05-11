//
// Created by lukas on 17.04.2025.
//

#include "main.h"
#include <math.h>

#include "../board/empty-cell.h"

bool isValidRow(BoardSizes boardSize, int row) {
    return row >= 0 && row < boardSize;
}

bool isValidColumn(BoardSizes boardSize, int column) {
    return column >= 0 && column < boardSize;
}

bool isValidSudokuRow(int **sudoku, BoardSizes boardSize, int row) {
    if (!isValidRow(boardSize, row)) {
        return false;
    }

    bool numbers[boardSize] = {};

    for (int i = 0; i < boardSize; i++) {
        numbers[i] = false;
    }

    for (int i = 0; i < boardSize; i++) {
        int number = sudoku[row][i] - 1;

        if (number == -1) continue;

        if (numbers[number]) return false;

        numbers[number] = true;
    }

    return true;
}

bool isValidSudokuColumn(int **sudoku, BoardSizes boardSize, int column) {
    if (!isValidColumn(boardSize, column)) {
        return false;
    }

    bool numbers[boardSize] = {};

    for (int i = 0; i < boardSize; i++) {
        numbers[i] = false;
    }

    for (int i = 0; i < boardSize; i++) {
        int number = sudoku[i][column] - 1;

        if (number == -1) continue;

        if (numbers[number]) return false;

        numbers[number] = true;
    }

    return true;
}

bool isValidSudokuSquare(int **sudoku, BoardSizes boardSize, int row, int column) {
    bool numbers[boardSize] = {};

    for (int i = 0; i < boardSize; i++) {
        numbers[i] = false;
    }

    int squareSize = (int) sqrt(boardSize);
    int rowStart = row / squareSize * squareSize;
    int columnStart = column / squareSize * squareSize;

    for (int i = rowStart; i < rowStart + squareSize; i++) {
        for (int j = columnStart; j < columnStart + squareSize; j++) {
            int number = sudoku[i][j] - 1;

            if (number == -1) continue;

            if (numbers[number]) return false;

            numbers[number] = true;
        }
    }

    return true;
}

bool isValidNumber(BoardSizes boardSize, int number) {
    return (number >= 1 && number <= boardSize) || number == EMPTY_CELL_SUDOKU;
}

bool isSudokuValid(int **sudoku, BoardSizes boardSize) {
    int squareLength = (int) sqrt(boardSize);

    int squareRow = 0;
    int squareColumn = 0;

    for (int i = 0; i < boardSize; i++) {
        if (
            !isValidSudokuRow(sudoku, boardSize, i) ||
            !isValidSudokuColumn(sudoku, boardSize, i) ||
            !isValidSudokuSquare(sudoku, boardSize, squareRow, squareColumn)
            ) {
            return false;
        }

        if (i != 0 && i % squareLength == 0) {
            squareRow++;
        }

        squareColumn = (squareColumn + squareLength) % boardSize;
    }

    return true;
}

bool isValidRowToAddNumber(int **sudoku, BoardSizes boardSize, int row, int number) {
    if (number == EMPTY_CELL_SUDOKU) {
        return true;
    }

    for (int i = 0; i < boardSize; i++) {
        if (number == sudoku[row][i]) return false;
    }

    return true;
}

bool isValidColumnToAddNumber(int **sudoku, BoardSizes boardSize, int column, int number) {
    if (number == EMPTY_CELL_SUDOKU) {
        return true;
    }

    for (int i = 0; i < boardSize; i++) {
        if (number == sudoku[i][column]) return false;
    }

    return true;
}

bool isValidSquareToAddNumber(int **sudoku, BoardSizes boardSize, int row, int column, int number) {
    if (number == EMPTY_CELL_SUDOKU) {
        return true;
    }

    int squareSize = (int) sqrt(boardSize);
    int row_start = row / squareSize * squareSize;
    int column_start = column / squareSize * squareSize;

    for (int i = row_start; i < row_start + squareSize; i++) {
        for (int j = column_start; j < column_start + squareSize; j++) {
            if (sudoku[i][j] == number) {
                return false;
            }
        }
    }

    return true;
}

bool isValidPosition(BoardSizes boardSize, int row, int column) {
    return row >= 0 && row < boardSize && column >= 0 && column < boardSize;
}

bool isValidPositionToAddNumber(int **sudoku, BoardSizes boardSize, int row, int column, int number) {
    return (
        isValidSquareToAddNumber(sudoku, boardSize, row, column, number) &&
        isValidRowToAddNumber(sudoku, boardSize, row, number) &&
        isValidColumnToAddNumber(sudoku, boardSize, column, number)
    );
}