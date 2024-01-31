#include <bits/stdc++.h>
using namespace std;
// solve using coin change problem using recursion
// If that amount of money cannot be made up by any combination of the coins, return -1.

int coinChange(vector<int>& coins, int amount) {
    if(amount == 0) return 0;
    int ans = INT_MAX;
    for(int i = 0; i < coins.size(); i++) {
        if(amount - coins[i] >= 0) {
            int subAns = coinChange(coins, amount - coins[i]);
            if(subAns != -1) {
                ans = min(ans, subAns + 1);
            }
        }
    }
    return ans == INT_MAX ? -1 : ans;
}

//using dp 

int solve( vector<int> &coins, int amount, vector<int> &dp) {

    if(amount == 0 ) return 1;
    if(dp[amount] != -1) return dp[amount];
    int ans = INT_MAX;
    for(int i = 0; i < coins.size(); i++) {
        if(amount - coins[i] >= 0) {
            int subAns = coinChange(coins, amount - coins[i]);
            if(subAns != -1) {
                ans = min(ans, subAns + 1);
            }
        }
    }
    return dp[amount] = ans == INT_MAX ? -1 : ans;

}

//using dp tabulation bottom up approach

int solve(vector<int> &coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    for(int i = 1; i <= amount; i++) {
        for(int j = 0; j < coins.size(); j++) {
            if(i - coins[j] >= 0) {
                int subAns = dp[i - coins[j]];
                if(subAns != INT_MAX) {
                    dp[i] = min(dp[i], subAns + 1);
                }
            }
        }
    }
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}
int main() {

    vector<int> coins = {1,2,5};
    int amount = 11;
    vector<int> dp(amount + 1, -1);
    // cout << coinChange(coins, amount) << endl;
    cout << solve(coins, amount, dp) << endl;
    return 0;
}