#include <bits/stdc++.h>
using namespace std;

bool compatre(int a, int b){
    string s1 = to_string(a);
    string s2 = to_string(b);

    return s1+s2 > s2+s1;

}

int main() {

    vector<int> v = {1,54,68,92,44};

    string s ;
    for ( int i: v) {
        s += to_string(i);
    }
    
    sort(s.begin(), s.end(), compatre);
    cout<<s<<endl;
   


    return 0;
}