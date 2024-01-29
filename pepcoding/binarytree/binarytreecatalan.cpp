#include <bits/stdc++.h>
using namespace std;

int noOfBST(int n){
    if(n==0){
        return 1;
    }

    int ans = 0;
    for(int i=1;i<=n;i++){
        //this is a catalan formula for no of BSTs with n nodes and i as root node 
        // catalan  = (2nCn)/(n+1)
        // worst case time complexity is O(n^n);

        ans += noOfBST(i-1)*noOfBST(n-i);
    }
    return ans;
}
int noOfBSTusingDP(int n){
    //complexity is O(n^2)
    //Its is filing in this manner 1,1,2,5,14,42,132,429,1430,4862,16796,58786,208012
    int dp[n+1];
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2;i<=n;i++){
        dp[i] = 0;
        for(int j=1;j<=i;j++){
            dp[i] += dp[j-1]*dp[i-j];
        }
    }
    return dp[n];
}
int f ( int n , int dp[]){
    if(n==0){
        return 1;
    }
   
    if(dp[n]!=-1){
        return dp[n];
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        ans += f(i-1,dp)*f(n-i,dp);
    }
    return dp[n] = ans;

}



int main() {

    cout<<noOfBST(16)<<endl;

    return 0;
}