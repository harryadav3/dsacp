#include <bits/stdc++.h>
using namespace std;

//convert s1->s2 operation are repalce, insert, delete

int solve(string s1, string s2, int i, int j) {
    if(i == s1.size() && j == s2.size()) {
        return 0;
    }
    if(i == s1.size()) {
        return s2.size()-j;
    }
    if(j == s2.size()) {
        return s1.size()-i;
    }
    if(s1[i] == s2[j]) {
        return solve(s1, s2, i+1, j+1);
    }
    int insert = solve(s1, s2, i, j+1);
    int delete_ = solve(s1, s2, i+1, j);
    int replace = solve(s1, s2, i+1, j+1);
    return 1 + min(insert, min(delete_, replace));
}
//using dp
int solve(string s1, string s2, int i, int j, vector<vector<int>> &dp) {
    if(i == s1.size() && j == s2.size()) {
        return 0;
    }
    if(i == s1.size()) {
        return s2.size()-j;
    }
    if(j == s2.size()) {
        return s1.size()-i;
    }
    if(dp[i][j] != -1) {
        return dp[i][j];
    }
    if(s1[i] == s2[j]) {
        return solve(s1, s2, i+1, j+1, dp);
    }
    int insert = solve(s1, s2, i, j+1, dp);
    int delete_ = solve(s1, s2, i+1, j, dp);
    int replace = solve(s1, s2, i+1, j+1, dp);
    dp[i][j] = 1 + min(insert, min(delete_, replace));
    return dp[i][j];
}

int main() {

    string s1 = "froot";
    string s2 = "fruit";
    cout<<solve(s1, s2, 0, 0)<<endl;
    

    return 0;
}