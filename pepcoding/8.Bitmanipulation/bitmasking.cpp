#include <bits/stdc++.h>
using namespace std;

int setithbit(int  n, int i){
    return n | ( 1 << i);
}
int getithbit(int n,int i){

    return n & ( 1 << i);
}

int clearithbit(int n, int i) {
    return ( n & ( ~(1<<i)));
}
int updateithbit(int n, int i , int bit){
    
    return n& ( ~ ( 1<< i)) | (bit << i);
}
int countallsetbits(int n){

    int count = 0;
        /*
            int count = 0;
            while(n) {
                n = n & ( n-1);
                count++;
            }

        */

       while(n>0){
        count += (n&1);
        n= n>>1;
       }

       return n;
}
int clearrangeofbits(int n, int i, int j){

    int a = (~0) << ( i+ 1);
    int b = ( 1<<j ) - 1;

    int mask  = a | b;
    int ans = n & mask;
    
    return ans;
}

int main() {

    int n=10, i=2;
    cout<<setithbit(n,i);

    return 0;
}


