//
// Created by lukas on 29.04.2025.
//
#pragma once

#ifndef BOARD_COUNT_EMPTY_CELLS_H
#define BOARD_COUNT_EMPTY_CELLS_H

#include "../board-sizes/board-sizes.h"

/**
 * @brief Counts the number of empty cells on the Sudoku board.
 *
 * @param sudoku A 2D array representing the Sudoku board.
 * @param boardSize The size of the Sudoku board.
 *
 * @return The total number of empty cells on the board.
 */
int countEmptyCells(int **sudoku, BoardSizes boardSize);

#endif //BOARD_COUNT_EMPTY_CELLS_H
