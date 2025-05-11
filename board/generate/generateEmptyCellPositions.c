//
// Created by lukas on 29.04.2025.
//

#include "generateEmptyCellPositions.h"

#include <stdlib.h>

#include "../empty-cell.h"

int** generateEmptyCellPositions(int **sudoku, BoardSizes boardSize, int emptyCellsCount) {
    int **positions = malloc(sizeof(int*) * emptyCellsCount);

    int positionsIndex = 0;

    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            if (sudoku[i][j] != EMPTY_CELL_SUDOKU) continue;

            positions[positionsIndex] = malloc(sizeof(int) * 2);
            positions[positionsIndex][0] = i;
            positions[positionsIndex][1] = j;

            positionsIndex++;
        }
    }

    return positions;
}

void freeEmptyCellPositions(int **positions, int emptyCellsCount) {
    for (int i = 0; i < emptyCellsCount; i++) {
        free(positions[i]);
    }

    free(positions);
}
