#include "../inc/sudoku.h"

void print_sudoku(int **grid) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool is_valid(int **grid, int row, int col, int num) {
    for (int i = 0; i < 9; i++) { // check row
        if (grid[row][i] == num) {
            return false;
        }
    }
    for (int i = 0; i < 9; i++) {   // check column
        if (grid[i][col] == num) {
            return false;
        }
    }
    row = (row / 3) * 3;
    col = (col / 3) * 3;
    for (int i = row; i < row + 3; i++) {   // check subgrid
        for (int j = col; j < col + 3; j++) {
            if (grid[i][j] == num) {
                return false;
            }
        }
    }
    return true;
}

int *next_empty(int **grid) {
    int *coord;

    coord = (int *)malloc(sizeof(int) * 2);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (grid[i][j] == 0) {
                coord[0] = i;
                coord[1] = j;
                return coord;
            }
        }
    }
    coord[0] = 9;
    coord[1] = 0;
    return coord;
}

bool solve_sudoku(int **grid, int row, int col) {
    int *coord = next_empty(grid);
    row = coord[0];
    col = coord[1];

    if (row > 8) {
        return true;
    }

    for (int num = 1; num <= 9; num++) {
        if (is_valid(grid, row, col, num)) {
            grid[row][col] = num;
            if (solve_sudoku(grid, row, col) == true) {
                return true;
            }
        }
        grid[row][col] = 0;
    }
    return false;  
}