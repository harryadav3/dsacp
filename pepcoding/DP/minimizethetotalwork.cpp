#include <bits/stdc++.h>
using namespace std;

/*
In ICO School, all students have to participate regularly in SUPW. There is a different SUPW activity each day, and each activity has its own duration. The SUPW schedule for the next term has been announced, including information about the number of minutes taken by each activity.


Nikhil has been designated SUPW coordinator. His task is to assign SUPW duties to students, including himself. The school's rules say that no student can go three days in a row without any SUPW duty.


Nikhil wants to find an assignment of SUPW duty for himself that minimizes the number of minutes he spends overall on SUPW.


Input format
Line 1: A single integer N, the number of days in the future for which SUPW data is available.

Line 2: N non-negative integers, where the integer in position i represents the number of minutes required for SUPW work on day i.

*/

//recursion 
int solverecurssion(int n, vector<int> &arr) {
   //mind of f(i+1) + a[i] or f(i+2) + a[i] or f(i+3) + a[i]

    if(n == 0) {
        return 0;
    }
    if(n == 1) {
        return arr[0];
    }
    if(n == 2) {
        return arr[0] + arr[1];
    }
    int f1 = solverecurssion(n-1, arr);
    int f2 = solverecurssion(n-2, arr);
    int f3 = solverecurssion(n-3, arr);
    return arr[n-1] + min(f1, min(f2, f3));
}

int solve(int n, vector<int> &arr) {
    vector<vector<int>> dp(3, vector<int>(n, 0));
    dp[0][0] = arr[0];
    dp[1][0] = arr[0];
    dp[2][0] = arr[0];
    for(int i = 1; i < n; i++) {
        dp[0][i] = arr[i] + min(dp[1][i-1], dp[2][i-1]);
        dp[1][i] = arr[i] + min(dp[0][i-1], dp[2][i-1]);
        dp[2][i] = arr[i] + min(dp[0][i-1], dp[1][i-1]);
    }
    return min(dp[0][n-1], min(dp[1][n-1], dp[2][n-1]));
}

 

int main() {

    int n = 10;
    vector<int> arr = {3, 2, 1, 1, 2, 3, 1, 3, 2, 1};

    cout<<solverecurssion(n, arr)<<endl;
    return 0;
}