//
// Created by lukas on 17.04.2025.
//
#pragma once

#ifndef SUDOKU_SOLVER_MAIN_H
#define SUDOKU_SOLVER_MAIN_HH

#include <stdbool.h>
#include "../board-sizes/board-sizes.h"

/**
 * @brief Returns an array of possible numbers for a given cell in Sudoku,
 * excluding the number already present in that cell.
 *
 * @param sudoku The 2D array representing the Sudoku board.
 * @param boardSize The size of the Sudoku board.
 * @param row The row index of the cell.
 * @param column The column index of the cell.
 *
 * @return A pointer to an array of possible numbers for the specified cell,
 *         excluding the number already in that cell (if any).
 */
int* possibleNumbersSudoku(int **sudoku, BoardSizes boardSize, int row, int column);

/**
 * @brief Helper function to check if the Sudoku is solvable.
 *
 * @param sudoku The 2D array representing the Sudoku board.
 * @param boardSize The size of the Sudoku board.
 * @param positions A 2D array of positions to check.
 * @param positionsIndex The current index in the positions array.
 *
 * @return true if the Sudoku is solvable, false otherwise.
 */
bool isSudokuSolvableHelper(int **sudoku, BoardSizes boardSize, int **positions, int positionsIndex);

/**
 * @brief Checks if the given Sudoku board has a solvable configuration.
 *
 * @param sudoku The 2D array representing the Sudoku board.
 * @param boardSize The size of the Sudoku board.
 *
 * @return true if the Sudoku is solvable, false otherwise.
 */
bool isSudokuSolvable(int **sudoku, BoardSizes boardSize);

/**
 * @brief Helper function to solve the Sudoku board recursively.
 *
 * @param sudoku The 2D array representing the Sudoku board.
 * @param boardSize The size of the Sudoku board.
 * @param positions A 2D array of positions to fill.
 * @param positionsIndex The current index in the positions array.
 *
 * @return true if the Sudoku is solved, false otherwise.
 */
bool solveSudokuHelper(int **sudoku, BoardSizes boardSize, int **positions, int positionsIndex);

/**
 * @brief Solves the Sudoku puzzle using a backtracking algorithm.
 *
 * @param sudoku The 2D array representing the Sudoku board.
 * @param boardSize The size of the Sudoku board.
 *
 * @return void
 */
void solveSudoku(int **sudoku, BoardSizes boardSize);

#endif //SUDOKU_SOLVER_MAIN_H
