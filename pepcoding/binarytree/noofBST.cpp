#include <bits/stdc++.h>
using namespace std;

 int noOfBST(int n){
     if(n==0){
         return 1;
     }
     if(n<0){
         return 0;
     }
     int ans = 0;
     ans += noOfBST(n-1);
     ans += noOfBST(n-2);
     ans += noOfBST(n-3);
     return ans;
 }
int main() {

    

    return 0;
}