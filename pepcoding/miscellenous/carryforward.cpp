#include <bits/stdc++.h>
using namespace std;

int main() {

    string s = "sagdaaega";
    int gcount = 0;
    int ans = 0;

    for ( int i=s.length() ; i>=0 ; i-- ) {
        if ( s[i] == 'g'){
            gcount++;
        }

        if ( s[i] == 'a'){
            ans+=gcount;
        }
    }
    cout << "The total pairs are " << ans << endl;
    return 0;
}