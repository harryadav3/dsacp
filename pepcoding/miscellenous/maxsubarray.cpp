#include <bits/stdc++.h>
using namespace std;

int main() {

    int arr[] = {-3,2,5,1,6,8,-1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 4;

    int wins = 0;
    for( int i = 0 ; i<k;i++){
        wins+=arr[i];
    }

    int j = k; int max = 0;
    while(j<n){
        if(wins>max) max=wins;
        int newwins = wins+arr[j];
        
    }


    return 0;
}