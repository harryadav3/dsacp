

#include <bits/stdc++.h>
using namespace std;


bool isSafe(vector<vector<int>> board, int i, int j, int num, int N){
    for(int x = 0; x < N; x++){
        if(board[i][x] == num || board[x][j] == num){
            return false;
        }
    }
    int rn = sqrt(N);
    int sx = (i/rn)*rn;
    int sy = (j/rn)*rn;
    for(int x = sx; x < sx+rn; x++){
        for(int y = sy; y < sy+rn; y++){
            if(board[x][y] == num){
                return false;
            }
        }
    }
    return true;
}

bool fill (vector<vector<int>> board, int i, int j, int N){
    if( i== N){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    if( j == N){
        return fill(board, i+1, 0, N);
    }
    if(board[i][j] != 0){
        return fill(board, i, j+1, N);
    }
    for(int num = 1; num <= 9; num++){
        if(isSafe(board, i, j, num, N)){
            board[i][j] = num;
            bool success = fill(board, i, j+1, N);
            if(success){
                return true;
            }
            board[i][j] = 0;
        }
    }
    return false;
}

int main() {

    
    vector<vector<int>> board = {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };

    fill(board, 0, 0, 9);


    return 0;
}