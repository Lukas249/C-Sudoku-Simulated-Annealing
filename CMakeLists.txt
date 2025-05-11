cmake_minimum_required(VERSION 3.30)
project(Sudoku_Simulated_Annealing C)

set(CMAKE_C_STANDARD 11)

include_directories(board)
include_directories(board/create)
include_directories(board/fill)
include_directories(board/generate)
include_directories(board-sizes)
include_directories(display)
include_directories(helpers)
include_directories(solver)
include_directories(validate)

add_executable(Sudoku_Simulated_Annealing
    board/create/main.c
    board/create/main.h
    board/fill/main.c
    board/fill/main.h
    board/generate/generateAllBoardPositions.c
    board/generate/generateAllBoardPositions.h
    board/generate/generateEmptyCellPositions.c
    board/generate/generateEmptyCellPositions.h
    board/generate/main.c
    board/generate/main.h
    board/countEmptyCells.c
    board/countEmptyCells.h
    board/empty-cell.h
    board-sizes/board-sizes.h
    board-sizes/main.c
    board-sizes/main.h
    display/main.c
    display/main.h
    helpers/delete-random-numbers.c
    helpers/delete-random-numbers.h
    helpers/generate-array.c
    helpers/generate-array.h
    helpers/get-random-number.c
    helpers/get-random-number.h
        solver/main.c
    solver/main.h
    validate/main.c
    validate/main.h
    main.c
        helpers/fill-array.c
        helpers/fill-array.h
        main.h)
