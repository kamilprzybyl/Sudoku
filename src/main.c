#include "../inc/sudoku.h"

int **init_grid() {
    int **grid;

    int static_grid[9][9] = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0}, 
        {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
        {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
        {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
        {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
        {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
        {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };

    grid = (int **)malloc(sizeof(int *) * 9);

    for (int i = 0; i < 9; i++) {
        grid[i] = (int *)malloc(sizeof(int) * 9);
        for (int j = 0; j < 9; j++) {
            grid[i][j] = static_grid[i][j];
        }
    }
    return grid;
}

int main() {
    int **grid;

    grid = init_grid();

    printf("\n     SUDOKU\n\n");
    print_sudoku(grid);
    if (solve_sudoku(grid, 0, 0) == false) {
        printf("Input invalid!\n");
    }
    printf("    SOLUTION\n\n");
    print_sudoku(grid);

    return 0;
}