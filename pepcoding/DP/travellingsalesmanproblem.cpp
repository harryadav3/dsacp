#include <bits/stdc++.h>
using namespace std;
//sovle the travelling slaesman problem
const int N = 1e5;
int n;
int dist[N][N];

int dp(int mask, int pos) {
    if(mask == (1 << n) - 1) {
        return dist[pos][0];
    }
    int ans = INT_MAX;
    for(int city = 0; city < n; city++) {
        if((mask & (1 << city)) == 0) {
            int newAns = dist[pos][city] + dp(mask | (1 << city), city);
            ans = min(ans, newAns);
        }
    }
    return ans;
}




int main() {

    

    return 0;
}