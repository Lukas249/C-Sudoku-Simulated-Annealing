//
// Created by lukas on 17.04.2025.
//
#pragma once

#ifndef BOARD_SIZES_MAIN_H
#define BOARD_SIZES_MAIN_H
#include <stdbool.h>

/**
 * @brief Checks if the provided board size is valid.
 *
 * This function checks whether the given board size matches one of the predefined
 * valid sizes (SMALL_BOARD, MEDIUM_BOARD, or LARGE_BOARD).
 *
 * @param boardSize The size of the Sudoku board to check.
 *
 * @return true if the board size is valid, false otherwise.
 */
bool isValidBoardSize(int boardSize);

#endif //BOARD_SIZES_MAIN_H
