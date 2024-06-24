
 #include <bits/stdc++.h>
 using namespace std;

 bool isSafe(vector<vector<int>> &board, int row, int col, int n){
     for(int i = row-1, j = col; i >= 0 ; i--){
         if(board[i][j] == 1){
             return false;
         }
     }
     for(int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--){
         if(board[i][j] == 1){
             return false;
         }
     }
     for(int i= row-1, j = col+1; i >= 0 && j < n; i--, j++){
         if(board[i][j] == 1){
             return false;
         }
     }
     return true;
     
 }  

    void solveNqueen(vector<vector<int>> &board, int row, int n) {
        if(row == n){
            for(auto i : board){
                for(auto j : i){
                    cout<<j<<" ";
                }
                cout<<endl;
            }
            cout<<"-----------------";
            cout<<endl;
            return;
        }
    
        for(int col = 0; col < n; col++){
            if(isSafe (board, row, col, n)){
                board[row][col] = 1;
                solveNqueen(board, row+1, n);
                board[row][col] = 0;
            }
        }
        
    }
 
 int main() {
 
        int n = 4;
        vector<vector<int>> board(n,vector<int>(n,0));
        solveNqueen(board, 0, n);

        for (auto i : board){
            for(auto j : i){
                cout<<j<<" ";
            }
            cout<<endl;
        }
     
 
     return 0;
 }