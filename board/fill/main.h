//
// Created by lukas on 17.04.2025.
//
#pragma once

#ifndef BOARD_FILL_MAIN_H
#define BOARD_FILL_MAIN_H

#include "../../board-sizes/board-sizes.h"

/**
 * Fills a single √n × √n square in the Sudoku board with numbers
 * that are not already present in that square.
 *
 * @param sudoku       The Sudoku board as a 2D array.
 * @param boardSize    The total size of the board (n × n).
 * @param squareIndex  The index of the square to fill, ranging from 0 to n-1,
 *                     ordered row by row from left to right.
 *
 * @return void
 */
void fillSudokuSquare(int **sudoku, BoardSizes boardSize, int squareIndex);

#endif //BOARD_FILL_MAIN_H
