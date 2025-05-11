//
// Created by lukas on 29.04.2025.
//

#ifndef GENERATEALLBOARDPOSITIONS_H
#define GENERATEALLBOARDPOSITIONS_H

#include "../../board-sizes/board-sizes.h"

/**
 * @brief Generates a 2D array of all board positions (row, column pairs).
 *
 * Each element in the returned array is a pointer to an array of two integers,
 * representing a coordinate (i, j) on the board.
 *
 * @param boardSize The size of the Sudoku board.
 *
 * @return A dynamically allocated array of size boardSize * boardSize, where each entry is a coordinate pair.
 */
int** generateAllBoardPositions(BoardSizes boardSize);

/**
 * @brief Frees the memory allocated by generateAllBoardPositions().
 *
 * @param positions A pointer to the 2D array of board positions to be freed.
 * @param boardSize The original board size used to determine allocation size.
 *
 * @return void
 */
void freeAllBoardPositions(int **positions, BoardSizes boardSize);

#endif //GENERATEALLBOARDPOSITIONS_H
