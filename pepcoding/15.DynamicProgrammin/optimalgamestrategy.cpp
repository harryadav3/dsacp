#include <bits/stdc++.h>
using namespace std;
// two players are A and B playing and chos to extreme no pick l/r and the player with max sum wins
// stragety to play the game give A have first change A will always win

//how to solve htis question
// get the sum of odd and even index and then find the max of them and then start from the max index 
// start from 
// find the maximise margin 

// recursive
int solve(vector<int> &coins, int i, int j) {
    if(i == j) return coins[i];
    if(i > j) return 0;
    int left = coins[i] + min(solve(coins, i + 2, j), solve(coins, i + 1, j - 1));
    int right = coins[j] + min(solve(coins, i + 1, j - 1), solve(coins, i, j - 2));
    return max(left, right);
}
/// function to calculate the Player A  best coins

// memoization
int solve(vector<int> &coins, int i, int j, vector<vector<int>> &dp) {
    if(i == j) return coins[i];
    if(i > j) return 0;
    if(dp[i][j] != 0) return dp[i][j];
    int left = coins[i] + min(solve(coins, i + 2, j, dp), solve(coins, i + 1, j - 1, dp));
    int right = coins[j] + min(solve(coins, i + 1, j - 1, dp), solve(coins, i, j - 2, dp));
    return dp[i][j] = max(left, right);
}

// tabulation
int solve(vector<int> &coins, int i, int j) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int gap = 0; gap < n; gap++) {
        for(int i = 0, j = gap; j < n; i++, j++) {
            if(i == j) dp[i][j] = coins[i];
            else if(i > j) dp[i][j] = 0;
            else {
                int left = coins[i] + min(dp[i + 2][j], dp[i + 1][j - 1]);
                int right = coins[j] + min(dp[i + 1][j - 1], dp[i][j - 2]);
                dp[i][j] = max(left, right);
            }
        }
    }
    return dp[0][n - 1];
}

int main() {

    vector<int> coins = { 3,16,1,4,32,28,7,6};
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    cout << solve(coins, 0, n - 1, dp) << endl;
    cout << solve(coins, 0, n - 1) << endl;


    return 0;
}