#include <bits/stdc++.h>
using namespace std;

// sell the wines to get a max profit
int maxprofit(vector<int> &arr, int i, int j, int y , vector<vector<int>> &dp) {
    if(i > j) {
        return 0;
    }
    if(dp[i][j] != -1) {
        return dp[i][j];
    }
    int year = y;
    int max1 = maxprofit(arr,i+1,j,y+1,dp) + arr[i]*year;
    int max2 = maxprofit(arr,i,j-1,y+1,dp) + arr[j]*year;
    int ans = max(max1,max2);
   
    return dp[i][j] = ans;
}

//tabulation
int maxprofit(vector<int> &arr, int n) {
    vector<vector<int>> dp(n,vector<int>(n,0));
    for(int i = 0; i < n; i++) {
        dp[i][i] = arr[i]*n;
    }
    for(int g = 1; g < n; g++) {
        for(int i = 0, j = g; j < n; i++,j++) {
             int year = n - (j-i);
            // int year = gap + 1;
            int max1 = dp[i+1][j] + arr[i]*year;
            int max2 = dp[i][j-1] + arr[j]*year;
            dp[i][j] = max(max1,max2);
        }
    }
    return dp[0][n-1];
}

// void printdiagonal(vector<vector<int>> &arr) {
//     int m = arr.size();
//     int n = arr[0].size();
//     for(int k= 0; k < n; k++) {
//         for(int i = 0, j = k; j < n; i++,j++) {
//             cout<<arr[i][j]<<" ";
//         }
//         cout<<endl;
     
//     }
    
// }

int main() {

    vector<int>arr = {5,1,4};
    int n = arr.size();
    vector<vector<int>> dp(n,vector<int>(n,-1));
    // cout<<maxprofit(arr,0,n-1,1,dp)<<endl;

    cout<<maxprofit(arr,n)<<endl;
    return 0;
}