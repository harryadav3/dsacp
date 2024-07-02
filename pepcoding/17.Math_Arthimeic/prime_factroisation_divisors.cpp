
#include <bits/stdc++.h>
using namespace std;


void make_all_divisors(vector<pair<int,int>> &fac, int inx, int res) {

    if( inx == fac.size()) {
        cout<<res<<endl;
        return;
    }

    for( int q =0; q<= fac[inx].second; q++) {

        int cnt = pow(fac[inx].first, q);
        make_all_divisors(fac, inx+1, res*cnt);
    }
}

int main() {

    int n = 3;
    vector<pair<int, int>> fac = {{2,3}, {3,4}, {5,6}};

    make_all_divisors(fac, 0, 1); 

    return 0;
}