//
// Created by lukas on 10.05.2025.
//

#pragma once

#ifndef MAIN_H
#define MAIN_H

#include <stdbool.h>
#include "board-sizes.h"

typedef struct {
    int **sudoku;
    int currentE;
    int bestE;
} SudokuAnnealingState;

/**
 * Creates a boolean matrix indicating which cells in the Sudoku board are fixed (non-empty).
 *
 * @param sudoku The initial Sudoku board.
 * @param boardSize The size of the Sudoku board.
 * @return A 2D boolean array where true indicates a fixed value.
 */
bool **sudokuFrozenValues(int **sudoku, BoardSizes boardSize);

/**
 * Frees the memory allocated for the frozen values boolean matrix.
 *
 * @param frozenValues The 2D boolean array to free.
 * @param boardSize The size of the Sudoku board.
 * @return void
 */
void freeSudokuFrozenValues(bool **frozenValues, BoardSizes boardSize);

/**
 * Calculates the current penalty (energy) of a Sudoku board for simulated annealing.
 * Lower penalty means the board is closer to a valid solution.
 *
 * @param sudoku The Sudoku board to evaluate.
 * @param boardSize The size of the Sudoku board.
 * @return The calculated penalty score.
 */
int calculatePenaltySA(int **sudoku, BoardSizes boardSize);

/**
 * Generates a new neighboring Sudoku board state by swapping non-fixed values within random smaller square.
 *
 * @param sudoku The current Sudoku board.
 * @param frozenValues Boolean matrix marking fixed cells.
 * @param boardSize The size of the Sudoku board.
 * @return A new 2D array representing a neighbor board state.
 */
int **generateNeighborSA(int **sudoku, bool **frozenValues, BoardSizes boardSize);

/**
 * Determines whether to accept a worse solution based on temperature and energy difference (penalty).
 *
 * @param T The current temperature.
 * @param deltaE The change in energy (penalty).
 * @return True if the move is accepted, false otherwise.
 */
bool acceptanceFunctionSA(const double T, const double deltaE);

/**
 * Runs the simulated annealing optimization algorithm on a Sudoku board.
 *
 * @param sudoku The initial Sudoku board.
 * @param boardSize The size of the Sudoku board.
 * @param frozenValues Boolean matrix indicating fixed cells.
 * @param startT Starting temperature.
 * @param endT Final temperature.
 * @param alpha Temperature decay factor.
 * @param maxIterations Maximum number of iterations.
 */
void runSudokuSA(int **sudoku, BoardSizes boardSize, bool **frozenValues, const double startT, const double endT, const double alpha, const int maxIterations);

#endif //MAIN_H
