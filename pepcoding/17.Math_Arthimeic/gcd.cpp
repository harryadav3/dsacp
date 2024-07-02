#include <bits/stdc++.h>
using namespace std;

int gcd( int x , int y ) {
    cout<< x << " " << y << endl;

    if( x == 0 || y == 0) return x + y;
    return gcd(y, x % y);
}

int main() {

   int n = 3;
   int m = 997; 
    cout<<gcd(n,m)<<endl;
    return 0;
}