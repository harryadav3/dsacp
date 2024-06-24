
#include <bits/stdc++.h>
using namespace std;    


    bool inBounds(int i, int j, vector<vector<char>> &grid){
        return ( i>= 0 && i< grid.size() && j>=0 && j<grid[0].size());
    }

    void dfs(int i, int j, vector<vector<char>> &grid, vector<vector<int>> &vis){

       vis[i][j] = 1;
        for( int r=-1; r<= 1; r++){
            for( int p = -1; p <= 1; p++){
               if( inBounds(r,p, grid)){
                   if((r==-1 && p==-1) || (r==-1 && p == 1) || (r==1 && p==1) || (r==1) && (p==-1)) continue; 
                   if(!vis[r][p] && grid[r][p] == '1'){
                       dfs(r,p,grid,vis);
                   }
               } 
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        
        int row= grid.size();
        int col= grid[0].size();

        vector<vector<int>> vis(row,vector<int>(col,0));

        int cnt = 0; 
        for( int i=0; i<row; i++) {
            for ( int j= 0; j<col ;j++) {
                if( !vis[i][j] && grid[i][j] == '1'){
                    cnt++;
                   dfs(i,j, grid, vis); 
                }
            }
        }


        return cnt;
        

        

    }
 int main() {

    return 0;
 }