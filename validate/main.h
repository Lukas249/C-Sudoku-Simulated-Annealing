//
// Created by lukas on 17.04.2025.
//

#pragma once

#ifndef VALIDATE_SUDOKU_MAIN_H
#define VALIDATE_SUDOKU_MAIN_H

#include <stdbool.h>
#include "../board-sizes/board-sizes.h"

/**
 * @brief Checks if the given row index is valid for the Sudoku board.
 *
 * @param boardSize The size of the Sudoku board.
 * @param row The row index to check.
 *
 * @return true if the row index is valid, false otherwise.
 */
bool isValidRow(BoardSizes boardSize, int row);

/**
 * @brief Checks if the given column index is valid for the Sudoku board.
 *
 * @param boardSize The size of the Sudoku board.
 * @param column The column index to check.
 *
 * @return true if the column index is valid, false otherwise.
 */
bool isValidColumn(BoardSizes boardSize, int column);

/**
 * @brief Checks if the given row in the Sudoku board is valid (i.e., contains no duplicate numbers).
 *
 * @param sudoku The 2D array representing the Sudoku board.
 * @param boardSize The size of the Sudoku board.
 * @param row The row index to check.
 *
 * @return true if the row is valid, false otherwise.
 */
bool isValidSudokuRow(int **sudoku, BoardSizes boardSize, int row);

/**
 * @brief Checks if the given column in the Sudoku board is valid (i.e., contains no duplicate numbers).
 *
 * @param sudoku The 2D array representing the Sudoku board.
 * @param boardSize The size of the Sudoku board.
 * @param column The column index to check.
 *
 * @return true if the column is valid, false otherwise.
 */
bool isValidSudokuColumn(int **sudoku, BoardSizes boardSize, int column);

/**
 * @brief Checks if the given square in the Sudoku board is valid (i.e., contains no duplicate numbers).
 *
 * @param sudoku The 2D array representing the Sudoku board.
 * @param boardSize The size of the Sudoku board.
 * @param row The starting row index of the square.
 * @param column The starting column index of the square.
 *
 * @return true if the square is valid, false otherwise.
 */
bool isValidSudokuSquare(int **sudoku, BoardSizes boardSize, int row, int column);

/**
 * @brief Checks if the given number is valid for the Sudoku board (within the range of valid numbers).
 *
 * @param boardSize The size of the Sudoku board.
 * @param number The number to check.
 *
 * @return true if the number is valid, false otherwise.
 */
bool isValidNumber(BoardSizes boardSize, int number);

/**
 * @brief Checks if the entire Sudoku board is valid (i.e., no duplicates in any row, column, or square).
 *
 * @param sudoku The 2D array representing the Sudoku board.
 * @param boardSize The size of the Sudoku board.
 *
 * @return true if the Sudoku is valid, false otherwise.
 */
bool isSudokuValid(int **sudoku, BoardSizes boardSize);

/**
 * @brief Checks if it's valid to add a number to the specified row in the Sudoku board.
 *
 * @param sudoku The 2D array representing the Sudoku board.
 * @param boardSize The size of the Sudoku board.
 * @param row The row index to check.
 * @param number The number to check.
 *
 * @return true if it's valid to add the number to the row, false otherwise.
 */
bool isValidRowToAddNumber(int **sudoku, BoardSizes boardSize, int row, int number);

/**
 * @brief Checks if it's valid to add a number to the specified column in the Sudoku board.
 *
 * @param sudoku The 2D array representing the Sudoku board.
 * @param boardSize The size of the Sudoku board.
 * @param column The column index to check.
 * @param number The number to check.
 *
 * @return true if it's valid to add the number to the column, false otherwise.
 */
bool isValidColumnToAddNumber(int **sudoku, BoardSizes boardSize, int column, int number);

/**
 * @brief Checks if it's valid to add a number to the specified square in the Sudoku board.
 *
 * @param sudoku The 2D array representing the Sudoku board.
 * @param boardSize The size of the Sudoku board.
 * @param row The starting row index of the square.
 * @param column The starting column index of the square.
 * @param number The number to check.
 *
 * @return true if it's valid to add the number to the square, false otherwise.
 */
bool isValidSquareToAddNumber(int **sudoku, BoardSizes boardSize, int row, int column, int number);

/**
 * @brief Checks if the given position (row, column) is valid on the Sudoku board.
 *
 * @param boardSize The size of the Sudoku board.
 * @param row The row index to check.
 * @param column The column index to check.
 *
 * @return true if the position is valid, false otherwise.
 */
bool isValidPosition(BoardSizes boardSize, int row, int column);

/**
 * @brief Checks if it's valid to add a number to the specified position (row, column) in the Sudoku board.
 *
 * @param sudoku The 2D array representing the Sudoku board.
 * @param boardSize The size of the Sudoku board.
 * @param row The row index to check.
 * @param column The column index to check.
 * @param number The number to check.
 *
 * @return true if it's valid to add the number to the position, false otherwise.
 */
bool isValidPositionToAddNumber(int **sudoku, BoardSizes boardSize, int row, int column, int number);

#endif //VALIDATE_SUDOKU_MAIN_H
