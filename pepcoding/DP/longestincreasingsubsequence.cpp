#include <bits/stdc++.h>
using namespace std;

//recursisve
int solve(vector<int> &arr, int idx, int prev) {
    if(idx == arr.size()) {
        return 0;
    }
    int taken = 0;
    if(arr[idx] > prev) {
        taken = solve(arr, idx+1, arr[idx]) + 1;
    }
    int nottaken = solve(arr, idx+1, prev);
    return max(taken, nottaken);
}

//memoization
int solve(vector<int> &arr, int idx, int prev, vector<int> &dp) {
    if(idx == arr.size()) {
        return 0;
    }
    if(dp[idx] != -1) {
        return dp[idx];
    }
    int taken = 0;
    if(arr[idx] > prev) {
        taken = solve(arr, idx+1, arr[idx], dp) + 1;
    }
    int nottaken = solve(arr, idx+1, prev, dp);
    dp[idx] = max(taken, nottaken);
    return dp[idx];
}
//solve using going from left and the the max conbinamtion from that number ot 0th index 
int masabsolution(vector<int> &arr) {
    vector<int> dp(arr.size(), 1);
    for(int i = 1; i < arr.size(); i++) {
        for(int j = 0; j < i; j++) {
            if(arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}

//tabulation
int solve(vector<int> &arr, int idx, int prev) {
    vector<int> dp(arr.size(), 0);
    for(int i = arr.size()-1; i >= 0; i--) {
        int taken = 0;
        if(arr[i] > prev) {
            taken = dp[i+1] + 1;
        }
        int nottaken = dp[i+1];
        dp[i] = max(taken, nottaken);
    }
    return dp[0];
}
//binary search
int solve(vector<int> &arr, int idx, int prev) {
    vector<int> dp;
    dp.push_back(arr[0]);
    for(int i = 1; i < arr.size(); i++) {
        if(arr[i] > dp.back()) {
            dp.push_back(arr[i]);
        } else {
            int idx = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
            dp[idx] = arr[i];
        }
    }
    return dp.size();
}

int main() {

   vector<int> arr  = { 3,2,4,1,7,8,6,10,9};
   // largest sequence lenght 
   vector<int> dp(arr.size(), -1);
   vector<int> len(arr.size(), 1);
    cout << solve(arr, 0, INT_MIN, dp) << endl;
    cout << solve(arr, 0, INT_MIN) << endl;

    return 0;
}