// write the brute force adn optimal approcach solution for climbing stairs leetcode problem
 
#include<iostream>
#include<vector>
using namespace std;

int climbStairs(int n) {
    if(n == 0) {
        return 1;
    }
    if(n < 0) {
        return 0;
    }
    int ans = climbStairs(n-1) + climbStairs(n-2);
    return ans;
}

int main() {
    int n = 3;
    cout<<climbStairs(n)<<endl;
    return 0;
}



// Path: pepcoding/DP/climbingstarits.cpp

#include<iostream>
#include<vector>
using namespace std;


int climbStairs(int n, vector<int> &dp) {
    if(n == 0) {
        return 1;
    }
    if(n < 0) {
        return 0;
    }
    if(dp[n] != -1) {
        return dp[n];
    }
    int ans = climbStairs(n-1,dp) + climbStairs(n-2,dp);
    dp[n] = ans;
    return ans;
}

int main() {
    int n = 3;
    vector<int> dp(n+1,-1);
    cout<<climbStairs(n,dp)<<endl;
    return 0;
}