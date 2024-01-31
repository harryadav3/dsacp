#include <bits/stdc++.h>
using namespace std;

void printdiagonal(vector<vector<int>> &arr) {
    int m = arr.size();
    int n = arr[0].size();
    for(int k= 0; k < n; k++) {
        for(int i = 0, j = k; j < n; i++,j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
     
    }
    
}

int main() {

    
     vector<vector<int>> arr = {
        {1,2,1,4,6},
        {6,8,7,-2,3},
        {4,3,2,1,6},
        {11,10,8,5,4},
        {12,15,6,3,7}
    };
    
    int m = arr.size();
    int n = arr[0].size();

    printdiagonal(arr);

    return 0;
}