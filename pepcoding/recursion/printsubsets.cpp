#include <bits/stdc++.h>
using namespace std;

void printsubsets(int i , string s ) {

        if ( i== s.length() - 1){
            cout<<s<<endl;
            return;
        }

        printsubsets(i+1,s.substr(0,i)+s.substr(i+1));

        
        
}

int main() {

    string s = "abc";
    printsubsets(0,s);

    return 0;
}