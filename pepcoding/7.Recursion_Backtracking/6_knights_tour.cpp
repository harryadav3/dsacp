#include <bits/stdc++.h>
using namespace std;


void display(vector<vector<int>> &board) {
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[0].size(); j++) {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}


void solve ( vector<vector<int>> &board, int sr, int sc, int move, int dx[], int dy[]) {
    if( move == board.size() * board[0].size()) {
        board[sr][sc] = move;
        display(board);
        board[sr][sc] = 0;
        return;
    }

    board[sr][sc] = move;
    for(int d = 0; d < 8; d++) {
        int nr = sr + dx[d];
        int nc = sc + dy[d];
        if( nr >= 0 && nc >= 0 && nr < board.size() && nc < board[0].size() && board[nr][nc] == 0) {
            solve(board, nr, nc, move+1, dx, dy);
        }
    }
    board[sr][sc] = 0;
}


int main() {


    int n = 5;
    int sr = 0 , sc = 0;
    vector<vector<int>> board(n, vector<int>(n, 0));
    int dx[] = {2,1,-1,-2,-2,-1,1,2};
    int dy[] = {1,2,2,1,-1,-2,-2,-1};
    solve( board, sr, sc, 1, dx, dy);    

    return 0;
}