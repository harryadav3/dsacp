#include <bits/stdc++.h>
using namespace std;

int main() {

    
    int n = 88;

    string s = "";

    while(n > 0) {
        int rem = n % 2;
        s.append(to_string(rem));
        n = n / 2;
    }

    reverse(s.begin(), s.end());    
    cout << s << endl;
    cout << ~8 << endl;

    return 0;
}