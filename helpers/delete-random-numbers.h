//
// Created by lukas on 17.04.2025.
//
#pragma once

#ifndef HELPERS_DELETE_K_RANDOM_NUMBERS_H
#define HELPERS_DELETE_K_RANDOM_NUMBERS_H

#include "../board-sizes/board-sizes.h"

/**
 * @brief Deletes random numbers from the Sudoku grid based on difficulty level.
 *
 * @param sudoku The 2D array representing the Sudoku game.
 * @param boardSize The size of the Sudoku board.
 * @param difficultyLevel The difficulty level which defines the maximum number of options available in starting cell of correct sequence.
 * @param maxDeleteNumbers The maximum number of cells that can be deleted (emptied).
 *
 * @return void
 */
void deleteRandomNumbers(int **sudoku, BoardSizes boardSize, int difficultyLevel, int maxDeleteNumbers);

#endif //HELPERS_DELETE_K_RANDOM_NUMBERS_H
