//
// Created by lukas on 09.04.2025.
//
#pragma once

#ifndef DISPLAY_H
#define DISPLAY_H

#include "../board-sizes/board-sizes.h"

/**
 * @brief Prints a single Sudoku cell.
 *
 * @param number The value of the cell to print.
 *
 * @return void
 */
void printSudokuCell(int number);

/**
 * @brief Prints a row of the Sudoku grid.
 *
 * @param sudoku The Sudoku grid.
 * @param row The row to print.
 * @param boardSize The size of the board.
 *
 * @return void
 */
void printSudokuRow(int **sudoku, int row, BoardSizes boardSize);

/**
 * @brief Prints a horizontal border for the Sudoku grid.
 *
 * @param boardSize The size of the board.
 *
 * @return void
 */
void printSudokuHorizontalBorder(BoardSizes boardSize);

/**
 * @brief Prints the entire Sudoku grid.
 *
 * @param sudoku The Sudoku grid.
 * @param boardSize The size of the board.
 *
 * @return void
 */
void printSudoku(int **sudoku, BoardSizes boardSize);


#endif //DISPLAY_H
