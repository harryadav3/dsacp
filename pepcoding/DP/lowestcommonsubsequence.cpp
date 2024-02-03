#include <bits/stdc++.h>
using namespace std;

 int solve(string s1, string s2) {
        vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, 0));
        for(int i = 1; i <= s1.size(); i++) {
            for(int j = 1; j <= s2.size(); j++) {
                if(s1[i-1] == s2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[s1.size()][s2.size()];
    
 }
 // bruteforce
    int solve(string s1, string s2, int i, int j) {
        if(i == s1.size() || j == s2.size()) {
            return 0;
        }
        if(s1[i] == s2[j]) {
            return solve(s1, s2, i+1, j+1) + 1;
        }
        int taken = solve(s1, s2, i+1, j);
        int nottaken = solve(s1, s2, i, j+1);
        return max(taken, nottaken);
    }
//recursion  wihtoud dp
    int solve (string s1, string s2, int i, int j) {
        if(i == s1.size() || j == s2.size()) {
            return 0;
        }
        if(s1[i] == s2[j]) {
            return solve(s1, s2, i+1, j+1) + 1;
        }
        int taken = solve(s1, s2, i+1, j);
        int nottaken = solve(s1, s2, i, j+1);
        return max(taken, nottaken);
    }
// Do by checking from backward wihtou dp
    int solve(string s1, string s2, int i, int j) {
        if(i == -1 || j == -1) {
            return 0;
        }
        if(s1[i] == s2[j]) {
            return solve(s1, s2, i-1, j-1) + 1;
        }
        int taken = solve(s1, s2, i-1, j);
        int nottaken = solve(s1, s2, i, j-1);
        return max(taken, nottaken);
    }


    int solve(string s1, string s2, int i, int j, vector<vector<int>> &dp) {
        if(i == s1.size() || j == s2.size()) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        if(s1[i] == s2[j]) {
            dp[i][j] = solve(s1, s2, i+1, j+1, dp) + 1;
            return dp[i][j];
        }
        int taken = solve(s1, s2, i+1, j, dp);
        int nottaken = solve(s1, s2, i, j+1, dp);
        dp[i][j] = max(taken, nottaken);
        return dp[i][j];
    }


//bottom up 
    int solve(string s1, string s2) {
        vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, 0));
        for(int i = 1; i <= s1.size(); i++) {
            for(int j = 1; j <= s2.size(); j++) {
                if(s1[i-1] == s2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[s1.size()][s2.size()];
    }
// print the string 

    string printstring(string s1, string s2) {
        vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, 0));
        for(int i = 1; i <= s1.size(); i++) {
            for(int j = 1; j <= s2.size(); j++) {
                if(s1[i-1] == s2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        string ans = "";
        int i = s1.size(), j = s2.size();
        while(i > 0 && j > 0) {
            if(s1[i-1] == s2[j-1]) {
                ans = s1[i-1] + ans;
                i--;
                j--;
            } else if(dp[i-1][j] > dp[i][j-1]) {
                i--;
            } else {
                j--;
            }
        }
        return ans;
    }

 

    int main() {

        string s1 = "abcd";
        string s2 = "agcfd";
        cout<<solve(s1, s2)<<endl;

        return 0;
    }
int main() {

    

    return 0;
}