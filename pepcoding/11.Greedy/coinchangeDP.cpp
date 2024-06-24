#include <bits/stdc++.h>
using namespace std;

int coinchangeGreedy(vector<int> &coins, int amount) {}

int coinchangeRecursion(vector<int> &coins, int amount, int idx) {
  if (amount == 0) {
    return 1;
  }
  if (idx == coins.size()) {
    return 0;
  }
  int count = 0;
  int ans = INT_MAX;

  for (int coin : coins) {
    if (amount - coin >= 0) {
      int subprop = coinchangeRecursion(coins, amount - coin, idx);
      ans = min(ans, subprop);
    }
  }

  return ans;

  // if(amount - coins[idx] >= 0) {
  //     count += coinchangeRecursion(coins, amount - coins[idx], idx);
  // }
  // count += coinchangeRecursion(coins, amount, idx + 1);
  // return count;
}

int coinChangeDynamicProgrammingTopDownRecursion(vector<int> &coins, int amount,
                                                 int idx, vector<int> &dp) {
  if (amount == 0) {
    return 1;
  }
  if (idx == coins.size()) {
    return 0;
  }
  if (dp[amount] != -1) {
    return dp[amount];
  }
  int count = 0;
  int ans = INT_MAX;

  for (int coin : coins) {
    if (amount - coin >= 0) {
      int subprop = coinchangeRecursion(coins, amount - coin, idx);
      ans = min(ans, subprop);
    }
  }

  int coinChangeDynamicProgrammingBottomUpIterateive(vector<int> & coins,
                                                     int amount) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= amount; i++) {
      for (int coin : coins) {
        if (i - coin >= 0) {
          dp[i] += dp[i - coin];
        }
      }
    }
    return dp[amount];
  }

  int masabDpCodeiterative(vector<int> & coins, int amount) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= amount; i++) {
      for (int coin : coins) {
        if (i - coin >= 0 && dp[i - coin] != INT_MAX) {
          int subprob = dp[i - coin];
          ans = min(and, subprob + 1);
        }
        dp[i] = ans;
      }
    }
    return dp[amount];
  }

  int masabDpCodeRecursion(vector<int> & coins, int amount, int dp[], int n) {

    if (amount == 0) {
      return 0;
    }
    if (d[amount] != -1) {
      return dp[amount];
    }

    int ans = INT_MAX;
    for (int coin : coins) {
      if (amount - coin >= 0) {
        int subprop = coinchangeRecursion(coins, amount - coin, idx);
        ans = min(ans, subprop);
      }
    }

    return dp[amount] = ans;
  }
  int main() {
    vector<int> coins = {1, 7, 10};
    int amount = 15;
    cout << coinchangeRecursion(coins, amount, 0) << endl;
    return 0;
  }
