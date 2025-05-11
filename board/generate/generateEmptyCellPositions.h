//
// Created by lukas on 29.04.2025.
//
#pragma once

#ifndef GENERATE_EMPTY_CELL_POSITIONS_H
#define GENERATE_EMPTY_CELL_POSITIONS_H

#include "../../board-sizes/board-sizes.h"

/**
 * @brief Generates a list of positions (row, column) of all empty cells in the Sudoku board.
 *
 * @param sudoku A 2D array representing the Sudoku board.
 * @param boardSize The size of the Sudoku board.
 * @param emptyCellsCount The number of empty cells in Sudoku.
 *
 * @return A dynamically allocated array of pointers to coordinate pairs.
 */
int** generateEmptyCellPositions(int **sudoku, BoardSizes boardSize, int emptyCellsCount);

/**
 * @brief Frees memory allocated by generateEmptyCellPositions().
 *
 * @param positions A pointer to the array of empty cell positions.
 * @param emptyCellsCount The number of empty cells in Sudoku (length of the positions array).
 *
 * @return void
 */
void freeEmptyCellPositions(int **positions, int emptyCellsCount);

#endif //GENERATE_EMPTY_CELL_POSITIONS_H
