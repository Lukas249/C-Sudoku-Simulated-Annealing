//
// Created by lukas on 17.04.2025.
//

#include "main.h"

#include "board-sizes.h"

bool isValidBoardSize(int boardSize) {
    return boardSize == SMALL_BOARD || boardSize == MEDIUM_BOARD || boardSize == LARGE_BOARD;
}