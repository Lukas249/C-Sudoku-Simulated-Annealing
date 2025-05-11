//
// Created by lukas on 29.04.2025.
//

#include "countEmptyCells.h"

#include "empty-cell.h"

int countEmptyCells(int **sudoku, BoardSizes boardSize) {
    int emptyCellsCount = 0;

    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            if (sudoku[i][j] == EMPTY_CELL_SUDOKU) emptyCellsCount++;
        }
    }

    return emptyCellsCount;
}
