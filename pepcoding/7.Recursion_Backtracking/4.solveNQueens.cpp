// solve nqueen using row

 #include <bits/stdc++.h>
 using namespace std;

 bool isSafe(vector<string> &nqueen, int row, int col, int n){
    // checking for the column where the queen is placed
     for(int i = row-1, j = col; i >= 0 ; i--){
            if(nqueen[i][j] == 'Q'){
                return false;
            }
    // checking for the left diagonal where the queen is placed
    for(int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--){
            if(nqueen[i][j] == 'Q'){
                return false;
            }
        }
    // checking for the right diagonal where the queen is placed
    for(int i= row-1, j = col+1; i >= 0 && j < n; i--, j++){
            if(nqueen[i][j] == 'Q'){
                return false;
            }
        }
     }
     return true;
     
 }



void solveNqueen(vector<vector<string>> &board, vector<string> &nqueen, int row, int n) {
    if(row == n){
        board.push_back(nqueen);
        return;
    }

    for(int col = 0; col < n; col++){
        if(isSafe (nqueen, row, col, n)){
            nqueen[row][col] = 'Q';
            solveNqueen(board, nqueen, row+1, n);
            nqueen[row][col] = '.';
        }
    }
    
}

int main(){
    int n = 4;

    vector<vector<string>> board;
    vector<string> nqueen(n,string(n,'.'));
    solveNqueen( board, nqueen, 0, n);

    for(auto i : board){
        for(auto j : i){
            for (auto k : j){
                cout<<k<<" ";
            }
            cout<<endl;
        }
        cout<<"-----------------";
        cout<<endl;
    }
    return 0;
}