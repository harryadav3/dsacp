#include <bits/stdc++.h>
using namespace std;


int frogjump(vector<int> &arr, int idx, vector<int> &dp) {
    if(idx == arr.size()-1) {
        return 0;
    }
    // if(idx >= arr.size()) {
    //     return INT_MAX;
    // }
    if(dp[idx] != -1) {
        return dp[idx];
    }
    


    return dp[idx] = min(frogjump(arr,idx+1,dp) + abs(arr[idx] - arr[idx+1]), frogjump(arr,idx+2,dp) + abs(arr[idx] - arr[idx+2]));
}
int masabsolution(vector<int> &arr, int n, vector<int> &dp) {
    
        if(n == 1) {
            return 0;
        }

        if(dp[n] != -1) {
            return dp[n];
        }

        int cost1 = INT_MAX , cost2 = INT_MAX;
        // if(idx+1 < n) {
        //     cost1 = masabsolution(arr,idx+1,dp) + abs(arr[idx] - arr[idx+1]);
        // }
        // if(idx+2 < n) {
        //     cost2 = masabsolution(arr,idx+2,dp) + abs(arr[idx] - arr[idx+2]);
        // }

        // cost1 = masabsolution(arr,n-1,dp) + abs(arr[n] - arr[n-1]);
        // cost2 = masabsolution(arr,n-2,dp) + abs(arr[n] - arr[n-2])

        if(n-1 >= 0) {
            cost1 = masabsolution(arr,n-1,dp) + abs(arr[n] - arr[n-1]);
        }
        if(n-2 >= 0) {
            cost2 = masabsolution(arr,n-2,dp) + abs(arr[n] - arr[n-2]);
        }


        return dp[n] = min(cost1,cost2);
    }

    //bottom up solution
    int masabsolution(vector<int> &arr, int n) {
        vector<int> dp(n+1,0);
        dp[0] = 0;
        dp[1] = abs(arr[1] - arr[0]);
        for(int i = 2; i <= n; i++) {
            int cost1 = dp[i-1] + abs(arr[i] - arr[i-1]);
            int cost2 = dp[i-2] + abs(arr[i] - arr[i-2]);
            dp[i] = min(cost1,cost2);
        }
        return dp[n];
    }

    
int main() {

    vector<int> arr = {10,20,30,10};
    int n = arr.size();
    vector<int> dp(arr.size(),-1);

    // cout<<frogjump(arr,0,dp)<<endl;
    cout<<masabsolution(arr,n-1,dp)<<endl;


    return 0;
}