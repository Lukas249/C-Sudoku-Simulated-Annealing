# 🧩 Sudoku — Simulated Annealing
A Sudoku solver written in C that uses the Simulated Annealing algorithm to handle puzzles of various sizes and difficulty levels.

# 🧠 Solving Algorithm: Simulated Annealing
The board is initially filled randomly, ensuring that each box contains unique values.

Next, the Simulated Annealing algorithm is applied to gradually reduce conflicts in rows and columns.

The algorithm continues until it finds a valid solution with no conflicts, reaches the maximum number of iterations, or the temperature falls below a defined threshold.

# 🛠️ Development Environment
This project was developed using the following tools:
- IDE: CLion 2024.3.4
- Toolchain: Bundled MinGW w64 (version 11.0)
- CMake: Bundled version 3.30.5
- C Compiler: GCC 13.1.0
- Debugger: Bundled GDB 15.2
- C Standard: C23
