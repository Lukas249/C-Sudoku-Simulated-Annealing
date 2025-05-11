//
// Created by lukas on 20.04.2025.
//
#pragma once

#ifndef BOARD_CREATE_MAIN_H
#define BOARD_CREATE_MAIN_H

#include "../../board-sizes/board-sizes.h"

/**
 * Creates an empty sudoku filled with 0
 *
 * @param boardSize The size of the Sudoku board.
 *
 * @return empty sudoku filled with 0
 */
int** createSudoku(BoardSizes boardSize);

/**
 * Frees allocated memory for sudoku
 *
 * @param sudoku The Sudoku board.
 * @param boardSize The size of the Sudoku board.
 *
 * @return void
 */
void freeSudoku(int **sudoku, BoardSizes boardSize);

#endif //BOARD_CREATE_MAIN_H
