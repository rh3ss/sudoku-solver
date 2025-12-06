#include <iostream>
using namespace std;

class Sudoku{
    static constexpr int grid_size = 9;
    static constexpr int wildcard = 0;
    int sudoku[grid_size][grid_size];
    public:
        Sudoku(int input[grid_size][grid_size]) {
            for (int i = 0; i < grid_size; ++i) {
                for (int j = 0; j < grid_size; ++j) {
                    sudoku[i][j] = input[i][j];
                }
            }
        }
        void solve() {
            solve_sudoku_recursiv();
        }
        void print_sudoku() {
            printf("\n-------------------------\n");
            for (int i = 0; i < grid_size; ++i) {
                for (int j = 0; j < grid_size; ++j) {
                    if (j == 0) {
                        printf("| ");
                    }
                    printf("%d ", sudoku[i][j]);
                    if ((j + 1) % 3 == 0) {
                        printf("| ");
                    }
                }
                if ((i + 1) % 3 == 0) {
                    printf("\n-------------------------");
                }    
                printf("\n");
            }
        }
    private:
        void solve_sudoku_recursiv() {

        }
        
};

int main() {
    int sudoku_grid[9][9] = {
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
