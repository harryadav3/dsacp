#include <bits/stdc++.h>
using namespace std;


int minStepstoOneGreedy(int n) {
    int count = 0;
    while(n != 1) {
        if(n % 3 == 0) {
            n = n / 3;
        }
        else if(n % 2 == 0) {
            n = n / 2;
        }
        else {
            n = n - 1;
        }
        count++;
    }
    return count;
}
   
int minStepstoOneDP(int n, vector<int> &dp) {
    if(n == 1) {
        return 0;
    }
    if(dp[n] != -1) {
        return dp[n];
    }
    int count = 0;
    int ans = INT_MAX;
    if(n % 3 == 0) {
        int subprob = minStepstoOneDP(n / 3, dp);
        ans = min(ans, subprob);
    }
    if(n % 2 == 0) {
        int subprob = minStepstoOneDP(n / 2, dp);
        ans = min(ans, subprob);
    }
    int subprob = minStepstoOneDP(n - 1, dp);
    ans = min(ans, subprob);
    dp[n] = ans + 1;
    return dp[n];
}

int minStepstoOneDPBottomUp(int n) {
    vector<int> dp(n + 1, 0);
    dp[1] = 0;
    for(int i = 2; i <= n; i++) {
        int ans = INT_MAX;
        if(i % 3 == 0) {
            ans = min(ans, dp[i / 3]);
        }
        if(i % 2 == 0) {
            ans = min(ans, dp[i / 2]);
        }
        ans = min(ans, dp[i - 1]);
        dp[i] = ans + 1;
    }
    return dp[n];
}

int main() {


    // cout<<minStepstoOneGreedy(12)<<endl;
    int n = 10;
   vector<int> dp(n + 1, -1);
    cout<<"Greedy - "<<minStepstoOneGreedy(n)<<endl;
    cout<<"DP - "<<minStepstoOneDP(n,dp)<<endl;
    cout<<"DPITERATIVE - "<<minStepstoOneDPBottomUp(n)<<endl;
    return 0;
}