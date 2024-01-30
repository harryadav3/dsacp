#include <bits/stdc++.h>
using namespace std;






int longestconssequence  (vector<vector<int>> board){
    int n = board.size();
    int m = board[0].size();
    vector<vector<int>> dp(n, vector<int>(m,0));
    int ans = 0;
    for(int i = 0; i < n; i++){
        dp[i][0] = 1;
    }
    for(int i = 0; i < m; i++){
        dp[0][i] = 1;
    }
   //check in all direction
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            if(board[i][j] == board[i-1][j]+1){
                dp[i][j] = dp[i-1][j]+1;
            }
            if(board[i][j] == board[i][j-1]+1){
                dp[i][j] = dp[i][j-1]+1;
            }
            if(board[i][j] == board[i-1][j-1]+1){
                dp[i][j] = dp[i-1][j-1]+1;
            }
            if(board[i][j] == board[i-1][j+1]+1){
                dp[i][j] = dp[i-1][j+1]+1;
            }
            ans = max(ans, dp[i][j]);
        }
    }
    return ans;
}

int masabsolutionwithDP( int i, int j, int n, vector<vector<int>> board, vector<vector<int>> &dp){
    int m = board[0].size();
    int ans = 0;
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int x[] = { 0,-1,-1,-1,0,-1,1,1 };
    int y[] = {1,1,0,-1,-1,1,0,1 };

    for(int k = 0; k < 8; k++){
        int newi = i + x[k];
        int newj = j + y[k];
        if(newi >= 0 && newj >= 0 && newi < n && newj < m && board[newi][newj] == board[i][j]+1){
            int sublen = masabsolutionwithDP(newi, newj, n, board,dp);
            ans = max(ans, sublen);
        }
    }
    return ans;
}

int computeMaxLen( int i, int j, int N, vector<vector<int>> board){
    if(i < 0 || j < 0 || i >= N || j >= N){
        return 0;
    }

    int ans = 0;
    int x[] = { 0,-1,-1,-1,0,-1,1,1 };
    int y[] = {1,1,0,-1,-1,1,0,1 };

    for(int k = 0; k < 8; k++){
        int newi = i + x[k];
        int newj = j + y[k];
        if(newi >= 0 && newj >= 0 && newi < N && newj < N && board[newi][newj] == board[i][j]+1){
            int sublen = computeMaxLen(newi, newj, N, board);
            ans = max(ans, sublen);
        }
    }
    return ans+1;
}

int masabsolution(vector<vector<int>> board){
    int ans;
    int m = board.size();
    int n = board[0].size();

    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[0].size(); j++){
            ans = max(ans, computeMaxLen( i, j, n, board));
        }
    }
    return ans;

    // Without DP the complexity is N2*8^N*2 (N2 for the loop and 8^N*2 for the recursion)
    // And with db the complexity is N2 
}

int main() {

    vector<vector<int>> board = {
            {5 ,2 ,0 , 8},
            {4 ,1 ,6 , 7},
            {8 ,11,2 , 3},
            {10,7 ,24, 4},
            {9 ,12, 5, 23},
            {11,20,21, 22},
    };

vector<vector<int>> dp(board.size(), vector<int>(board[0].size(),-1));
    // int n = longestconssequence(board);
    // cout<< masabsolution(board);
    cout<< masabsolutionwithDP(0,0,board.size(),board,dp);
    

    return 0;
}