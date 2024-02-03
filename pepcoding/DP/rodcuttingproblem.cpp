#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &price) {
    int n = price.size();
    vector<int> dp(n, 0);
    dp[0] = price[0];
    for(int i = 1; i < n; i++) {
        int maxVal = price[i];
        for(int j = 0; j < i; j++) {
            maxVal = max(maxVal, dp[j] + dp[i - j - 1]);
        }
        dp[i] = maxVal;
    }
    return dp[n - 1];
}

//recursive 
int maxProfit(vector<int> &price, int n) {
    if(n == 0) return 0;
     int maxVal = price[n - 1];
    for(int i = 0; i < n; i++) {
        maxVal = max(maxVal, price[i]+ maxProfit(price, n - i - 1));
    }
    return maxVal;
}


//memoization
int maxProfit(vector<int> &price, int n, vector<int> &dp) {
    if(n == 0) return 0;
    if(dp[n] != -1) return dp[n];
     int maxVal = price[n - 1];
    
    for(int i = 0; i < n; i++) {
        maxVal = max(maxVal, price[i] + maxProfit(price, n - i - 1));
    }
    return dp[n] = maxVal;
}


int main() {

    vector<int> price = {1,5,8,9,10,17,17,20};
    int n = price.size();
    vector<int> dp(n + 1, -1);
    cout << maxProfit(price) << endl;
    cout << maxProfit(price,price.size(), dp) << endl;
    cout << maxProfit(price,price.size()) << endl;
    return 0;
}