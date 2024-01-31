// a person can ake k size jumps , count all ways to reach top


#include <bits/stdc++.h>
using namespace std;

// without DP = O(k^n)
// with DP = O(n*k)
// memoization top down
int countWays(int n, int k, vector<int> &dp) {
    
    if( n == 0){
        return 1;
    }
    if( n<0) {
        return 0;
    }
    if(dp[n] != -1) {
        return dp[n];
    }
    int ans = 0;
    for ( int i = 1 ; i <= k; i++ ) {
        ans += countWays(n-i,k,dp);
    }

    return dp[n] = ans;
}

//tabulation 
int countWays(int n, int k) {
    vector<int> dp(n+1,0);
    dp[0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            if(i-j >= 0) {
                dp[i] += dp[i-j];
            }
        }
    }
    return dp[n];
}

int masabsolution( vector<int> &arr, int n,int k, vector<int> &dp) {

        dp[0] = 0;
        for( int i=1; i<=n;i++){
            int ans = 0;
            for(int j=1; j<=k;j++){
                if(i-j>=0){
                    ans += dp[i-j];
                }
            }
            dp[i] = ans;
        }

        return dp[n];
}

//solution using sliding window
int countWays(int n, int k) {
    vector<int> dp(n+1,0);
    dp[0] = 1;
    dp[1] = 1;
    int sum = 1;
    for(int i = 2; i <= n; i++) {
        if(i-k-1 >= 0) {
            sum -= dp[i-k-1];
        }
        sum += dp[i-1];
        dp[i] = sum;
    }
    return dp[n];
}

// solve using 2dp(n-1) - dp(n-k-1 )

 int solve() {

 } 
// tabulation optimized O(n) time and O(k) space complexity 
int countWays(int n, int k) {
    vector<int> dp(n+1,0);
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= k; i++) {
        dp[i] = 2*dp[i-1];
    }
    for(int i = k+1; i <= n; i++) {
        dp[i] = 2*dp[i-1] - dp[i-k-1];
    }
    return dp[n];
}
int main() {

    int n = 5;
    int k = 3;
    vector<int> dp(n+1,-1);
    cout<<countWays(n,k,dp)<<endl;


    return 0;
}