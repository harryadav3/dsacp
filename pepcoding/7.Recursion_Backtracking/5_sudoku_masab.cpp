#include <bits/stdc++.h>
using namespace std;

const int N = 9;
int grid[N][N] = {
    {3, 0, 6, 5, 0, 8, 4, 0, 0},
    {5, 2, 0, 0, 0, 0, 0, 0, 0},
    {0, 8, 7, 0, 0, 0, 0, 3, 1},
    {0, 0, 3, 0, 0, 0, 1, 8, 0},
    {9, 0, 0, 8, 6, 3, 0, 0, 5},
    {0, 5, 0, 0, 9, 0, 6, 0, 0},
    {1, 3, 0, 0, 0, 0, 2, 5, 0},
    {0, 0, 0, 0, 0, 0, 0, 7, 4},
    {0, 0, 5, 2, 0, 6, 3, 0, 0}
};




bool isSafe(int row , int col , int digit) {

   // row check
    for(int i = 0; i < N; i++) {
        if(grid[row][i] == digit) {
            return false;
        }
    }

    // col check
    for(int i = 0; i < N; i++) {
        if(grid[i][col] == digit) {
            return false;
        }
    }

    // grid 
    int start_row = row - row%3 , start_col = col - col%3;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(grid[i+start_row][j+start_col] == digit) {
                return false;
            }
        }
    }
    return true; 
}


void sudoku_solver( int row , int col ) {
    if(row == N) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        return;
    }

    if(col == N) {
        sudoku_solver(row+1, 0);
        return;
    }

    if( grid[row][col] ==  0) {
        for( int digit = 1; digit <= 9; digit++) {
            if(isSafe(row, col, digit)) {
                grid[row][col] = digit;
                sudoku_solver(row, col+1);
                grid[row][col] = 0;
            }
        }
    } else {
        sudoku_solver(row, col+1);
    }

}

int main() {

    sudoku_solver(0, 0);
    return 0;
}
