#include <bits/stdc++.h>
using namespace std;

int main() {

    int arr[] = {1,6,4,6,5,1,5,2,6,4,4,2,1,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    int min  = INT_MAX; int max = INT_MIN;

    for(int i = 0; i < n; i++) {
        if(arr[i] < min) min =arr[i];
        if(arr[i] > max) max = arr[i];
    }
    cout<<"Min " << min << "MAX " << max << endl;

    int A = -1;
    int B = -1;
    int windowsize = 0;
    int ans = 0;

    for  ( int i = n -1 ; i >= 0; i--){
        if( arr[i] == min) 
            A = i;
        if(arr[i] == max ) 
            B = i;

        windowsize = abs(A-B) + 1;
        cout<<"The current windows size"<<windowsize<< " A = " << A << " B = "<< B << endl;
        if( ans < windowsize)
            ans = windowsize;

           
    }
    
    cout<< "The min window is of size " << ans << endl;

    return 0;
}