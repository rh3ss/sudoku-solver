# Sudoku Solver #

This repository contains a C++ implementation of a Sudoku solver designed to address _Problem 989 – Su Doku_ from the _UVa Online Judge_ platform: https://onlinejudge.org/external/9/989.pdf

## Short intro

This solver uses a depth-first search technique, commonly known as brute-force backtracking. The algorithm processes the Sudoku grid step by step, starting from the top-left corner and moving toward the bottom-right. Whenever it encounters an empty cell (represented by a 0), it tries to fill it with a number from 1 to 9. For each candidate number, the algorithm checks whether the value already appears in the same row, the same column, or within the corresponding 3×3 subgrid. If the number is valid in all three checks, it is temporarily placed into the cell, and the solver moves on to attempt filling the next one. If, however, a later step reveals that the puzzle cannot be solved with this choice, the algorithm resets the cell, removes the invalid number, and continues testing the remaining possibilities. If none of the digits from 1 to 9 fit in the current cell, the algorithm backtracks to the previous cell and tries a different value there. This process continues until either the puzzle is successfully completed or no solution exists.

| Input | Output |
|-------|--------|
| <img src="https://github.com/user-attachments/assets/daaa776f-97fc-4dd5-9e74-652eb9ab7d6d" width="150"> | <img src="https://github.com/user-attachments/assets/4ced1e51-67db-446f-9831-676e4ec7f1fa" width="150"> |


## Usage
The main() function demonstrates how to initialize and solve a Sudoku puzzle:

```
int main() {
    // create a 9 x 9 sudoku grid
    vector<vector<int>> sudoku_grid = {
        {0, 6, 0, 1, 0, 4, 0, 5, 0},
        {0, 0, 8, 3, 0, 5, 6, 0, 0},
        {2, 0, 0, 0, 0, 0, 0, 0, 1},
        {8, 0, 0, 4, 0, 7, 0, 0, 6},
        {0, 0, 6, 0, 0, 0, 3, 0, 0},
        {7, 0, 0, 9, 0, 1, 0, 0, 4},
        {5, 0, 0, 0, 0, 0, 0, 0, 2},
        {0, 0, 7, 2, 0, 6, 9, 0, 0},
        {0, 4, 0, 5, 0, 8, 0, 7, 0}
    };
    Sudoku sudoku(sudoku_grid);
    sudoku.solve(); // solve current sudoku
    sudoku.print_sudoku(); // print solved sudoku

    return 0;
}
```
