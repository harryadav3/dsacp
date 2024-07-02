#include <bits/stdc++.h>
using namespace std;

int countpaths(int i, int j, int n, int m, vector<vector<int>> &maze, vector<vector<int>> &dp){
    if(i == n-1 && j == m-1){
        return 1;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int count = 0;
    if(i+1 < n && maze[i+1][j] != 1){
        count += countpaths(i+1, j, n, m, maze, dp);
    }
    if(j+1 < m && maze[i][j+1] != 1){
        count += countpaths(i, j+1, n, m, maze, dp);
    }
    return dp[i][j] = count;
}

void printAllpaths(int i, int j, int n, int m, vector<vector<int>> &maze, vector<vector<int>> &dp, string path){
    if(i == n-1 && j == m-1){
        cout<<path<<endl;
        return;
    }
    if(dp[i][j] != -1){
        return;
    }
    if(i+1 < n && maze[i+1][j] != 1){
        printAllpaths(i+1, j, n, m, maze, dp, path+"D");
    }
    if(j+1 < m && maze[i][j+1] != 1){
        printAllpaths(i, j+1, n, m, maze, dp, path+"R");
    }
    return;
}


void solveproblem(int i, int j, int n, int m, vector<vector<int>> &maze,  string path, vector<string> &ans){

   if( i <0 || j < 0 || i >= n || j >= m || maze[i][j] == 1 || maze[i][j] == 2){


       return;
   }
   if( i== m && j == n){
    ans.push_back(path);
    return;
   }
   maze[i][j] = 2;
    solveproblem(i+1, j, n, m, maze,  path+"D", ans);
    solveproblem(i, j+1, n, m, maze, path+"R", ans);
    solveproblem(i-1, j, n, m, maze, path+"U", ans);
    solveproblem(i, j-1, n, m, maze, path+"L", ans);
    maze[i][j] = 0;




}

int main() {

    vector<vector<int>> maze {
        {0,0,0,0,1},
        {0,0,0,0,0},
        {0,0,1,0,0},
        {0,0,1,0,0},
        {1,0,0,0,0}
       
    };
    int n = maze.size();
    int m = maze[0].size();
    vector<vector<int>> dp(n, vector<int>(m,-1));
    vector<string> ans;
    // cout<<countpaths(0,0,n,m,maze,dp);

    // printAllpaths(0,0,n,m,maze,dp,"");

    solveproblem(0,0,n,m,maze,"",ans);

    for(auto i : ans){
        cout<<i<<endl;
    }
    return 0;
}