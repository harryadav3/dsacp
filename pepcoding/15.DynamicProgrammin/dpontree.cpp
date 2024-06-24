#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

vector<int> gr[N];

int dp(int cur, int pra) {
    int ans = cur; 
    for ( auto child : gr[cur]) {
        if(child != pra) {
            ans += dp(child, cur);
        }
    }
    return ans;
}

int main() {

    

    return 0;
}