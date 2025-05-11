//
// Created by lukas on 29.04.2025.
//

#include "generateAllBoardPositions.h"

#include <stdlib.h>

int** generateAllBoardPositions(BoardSizes boardSize) {
    int **positions = malloc(sizeof(int*) * boardSize * boardSize);
    int positionsIndex = 0;

    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            positions[positionsIndex] = malloc(sizeof(int) * 2);
            positions[positionsIndex][0] = i;
            positions[positionsIndex][1] = j;

            positionsIndex++;
        }
    }

    return positions;
}

void freeAllBoardPositions(int **positions, BoardSizes boardSize) {
    for (int i = 0; i < boardSize*boardSize; i++) {
        free(positions[i]);
    }

    free(positions);
}
