#include <iostream>
#include <vector>

using namespace std;

class Sudoku {
    static constexpr int size = 9;          // standard size of 9
    static constexpr int wildcard = 0;      // set a wildcard for emtpy cells
    vector<vector<int>> sudoku;             // full 9 x 9 Sudoku grid
public:
    Sudoku(vector<vector<int>> input_sudoku) {
        this->sudoku = input_sudoku;
    }
    void solve() {
        solve_sudoku_recursiv(0, 0);
    }
    // prints the sudoku grid in a formatted way
    void print_sudoku() {
        printf("\n-------------------------\n");
        for (int row = 0; row < size; ++row) {
            for (int col = 0; col < size; ++col) {
                if (col == 0) { printf("| "); }
                printf("%d ", sudoku[row][col]);
                if ((col + 1) % 3 == 0) { printf("| "); }
            }
            if ((row + 1) % 3 == 0) {
                printf("\n-------------------------");
            }
            printf("\n");
        }
    }
private:
    // attempts to fill the board from position (row, col) to completion
    // returns 'true' if the board is successfully solved else 'false'
    bool solve_sudoku_recursiv(int row, int col) {
        // check if 'row' and 'col' reaches the bottom right corner of the grid,
        // meaning the entire grid is filled and no more possibilities are left
        if (row == size - 1 && col == size) {
            return true;
        }

        // check if index 'col' reaches the end of the line, prevent IndexOutOfBounds
        if (col == size) {
            col = 0, row++;
        }

        // if the current cell is already filled (1 to 9), move to the next column
        if (sudoku[row][col] != wildcard) {
            return solve_sudoku_recursiv(row, col + 1);
        }

        // try every number (1 to 9) in the current empty cell.
        // for each number:
        //   - check if placing it does not violate any Sudoku rule
        //   - if placement is valid, assign the number and recursively attempt to fill the next cell
        //   - if recursion 'true' back up the call stack to indicate success
        //   - if recursion 'false' reset the cell to empty and continue trying the next number
        for (int number = 1; number <= size; ++number) {
            if (is_number_placable(row, col, number)) {
                sudoku[row][col] = number;
                if (solve_sudoku_recursiv(row, col + 1)) {
                    return true;
                }
                sudoku[row][col] = wildcard;
            }
        }

        return false;
    }

    // checks if 'number' placement follows Sudoku rules: not in current row, column, or 3 x 3 subgrid
    // returns 'true' if placement is possible else 'false'
    bool is_number_placable(int row, int col, int number) {
        // check if 'number' is in current row
        for (int row_idx = 0; row_idx < size; ++row_idx) {
            if (sudoku[row][row_idx] == number) {
                return false;
            }
        }

        // check if 'number' is in current column
        for (int col_idx = 0; col_idx < size; ++col_idx) {
            if (sudoku[col_idx][col] == number) {
                return false;
            }
        }

        // check if 'number' is in current 3 x 3 subgrid
        int row_start_idx = row - (row % 3);
        int col_start_idx = col - (col % 3);
        for (int row_idx = 0; row_idx < size / 3; ++row_idx) {
            for (int col_idx = 0; col_idx < size / 3; ++col_idx) {
                if (sudoku[row_start_idx + row_idx][col_start_idx + col_idx] == number) {
                    return false;
                }
            }
        }

        return true;
    }
};

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
    sudoku.print_sudoku();
    sudoku.solve(); // solve current sudoku
    sudoku.print_sudoku(); // print solved sudoku

    return 0;
}