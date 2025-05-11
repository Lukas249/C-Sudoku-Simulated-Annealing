//
// Created by lukas on 17.04.2025.
//
#pragma once

#ifndef BOARD_SIZES_H
#define BOARD_SIZES_H

/**
 * @brief Enum representing different board sizes for Sudoku.
 *
 * This enum defines three possible sizes for the Sudoku board:
 * - SMALL_BOARD: 4x4 grid (used for smaller Sudoku)
 * - MEDIUM_BOARD: 9x9 grid (standard Sudoku size)
 * - LARGE_BOARD: 16x16 grid (used for larger and more complex Sudoku)
 */
typedef enum {
    SMALL_BOARD = 4, /**< 4x4 grid, typically for simpler puzzles */
    MEDIUM_BOARD = 9, /**< 9x9 grid, standard size for Sudoku */
    LARGE_BOARD = 16, /**< 16x16 grid, for more advanced puzzles */
} BoardSizes;

#endif //BOARD_SIZES_H
