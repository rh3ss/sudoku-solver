#include <iostream>
#include <vector>

using namespace std;

class Sudoku {
    static constexpr int size = 9;
    static constexpr int wildcard = 0;
    vector<vector<int>> sudoku;
public:
    Sudoku(vector<vector<int>> input_sudoku) {
        this->sudoku = input_sudoku;
    }
    void solve() {
        solve_sudoku_recursiv(0, 0);
    }
    void print_sudoku() {
        printf("\n-------------------------\n");
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (j == 0) { printf("| "); }
                printf("%d ", sudoku[i][j]);
                if ((j + 1) % 3 == 0) { printf("| "); }
            }
            if ((i + 1) % 3 == 0) {
                printf("\n-------------------------");
            }
            printf("\n");
        }
    }
private:
    bool solve_sudoku_recursiv(int row, int col) {
        if (row == size - 1 && col == size) {
            return true;
        }

        if (col == size) {
            col = 0, row++;
        }

        if (sudoku[row][col] != wildcard) {
            return solve_sudoku_recursiv(row, col + 1);
        }

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
    bool is_number_placable(int row, int col, int number) {
        for (int row_idx = 0; row_idx < size; ++row_idx) {
            if (sudoku[row][row_idx] == number) {
                return false;
            }
        }

        for (int col_idx = 0; col_idx < size; ++col_idx) {
            if (sudoku[col_idx][col] == number) {
                return false;
            }
        }

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
    sudoku.solve();
    sudoku.print_sudoku();

    return 0;
}
