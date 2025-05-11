//
// Created by lukas on 21.04.2025.
//

#include "main.h"
#include "../../display/main.h"
#include "../../solver/main.h"
#include "../create/main.h"
#include "../fill/main.h"

#include <math.h>

#include "../../helpers/delete-random-numbers.h"


int** generateSolvableSudoku(BoardSizes boardSize, int difficultyLevel) {
    const int squareSize = (int) sqrt(boardSize);

    int **sudoku = createSudoku(boardSize);

    if (boardSize >= 9) {
        for (int i = 0; i < boardSize; i += squareSize + 1) {
            fillSudokuSquare(sudoku, boardSize, i);
        }
    } else {
        fillSudokuSquare(sudoku, boardSize, 0);
    }

    solveSudoku(sudoku, boardSize);

    deleteRandomNumbers(sudoku, boardSize, difficultyLevel, 128);

    return sudoku;
}
