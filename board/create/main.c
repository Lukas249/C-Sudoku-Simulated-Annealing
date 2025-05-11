//
// Created by lukas on 20.04.2025.
//

#include "main.h"
#include "../../solver/main.h"
#include "../fill/main.h"

#include <stdio.h>
#include <stdlib.h>

#include "../empty-cell.h"

int** createSudoku(BoardSizes boardSize) {
    int **sudoku = malloc(sizeof(int*) * boardSize);

    if (sudoku == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return NULL;
    }

    for (int i = 0; i < boardSize; i++) {
        sudoku[i] = malloc(sizeof(int) * boardSize);

        for (int j = 0; j < boardSize; j++) {
            sudoku[i][j] = EMPTY_CELL_SUDOKU;
        }
    }

    return sudoku;
}

void freeSudoku(int **sudoku, BoardSizes boardSize) {
    for (int i = 0; i < boardSize; i++) {
        free(sudoku[i]);
    }

    free(sudoku);
}
