#ifndef _SUDOKU_H_
#define _SUDOKU_H_

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool solve_sudoku(int **grid, int row, int col);
int *next_empty(int **grid);
bool is_valid(int **grid, int row, int col, int num);
void print_sudoku(int **grid);

#endif