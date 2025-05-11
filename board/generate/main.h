//
// Created by lukas on 21.04.2025.
//
#pragma once

#ifndef BOARD_GENERATE_MAIN_H
#define BOARD_GENERATE_MAIN_H

#include "../../board-sizes/board-sizes.h"

/**
 * Generates a Sudoku puzzle with exactly one unique solution.
 * The boardSize determines the number of cells (boardSize^2).
 * The difficulty level determines the maximum number of options available in any cell.
 *
 * @param boardSize The size of the Sudoku board.
 * @param difficultyLevel The difficulty level which defines the maximum number of options available in any cell.
 *
 * @return A Sudoku with one unique solution.
 */
int** generateSolvableSudoku(BoardSizes boardSize, int difficultyLevel);

#endif //BOARD_GENERATE_MAIN_H
