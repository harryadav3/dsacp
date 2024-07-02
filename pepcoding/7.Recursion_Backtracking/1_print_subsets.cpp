#include <bits/stdc++.h>
using namespace std;

// print hte string substest

void print_substest_backtrack(string s, int i, string bucket){

    if( i == s.size()){
        cout<<bucket;
    }

    bucket += s[i];
    print_substest_backtrack(s, i+1, bucket);
    bucket.pop_back();
}

int main() {

    string s = "abc";
    printsubsets(0,s);

    return 0;
}