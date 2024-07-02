
#include <bits/stdc++.h>
using namespace std;

void solve(int open , int close , string res , int n ) {
    if( open + close == 2*n) {
        cout<<res<<endl;
        return;
    }

    if( open < n) {
        solve(open+1, close, res + "(", n);
    }

    if( close < open) {
        solve(open, close+1, res + ")", n);
    }

}


int main() {
    int n = 4;
    solve(0, 0 , "", n); 

    return 0;
}