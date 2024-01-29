#include <bits/stdc++.h>
using namespace std;

int main() {

    int arr[] = {-3,0,1,3,6,8,11,14,18,20,25};

    int tar  = 5;

    int n = sizeof(arr)/sizeof(arr[0]);
    int count  = 0;
    int s=0; int e= 1;
    while(e < s){
        
        if(arr[e] - arr[s] > tar) {
            s++;
        }
        else if(arr[e] - arr[s]  == tar) {
            count++; s++; e++;
        } else {
            e++;
        }

    }
    cout<<count<<endl;

    return 0;
}