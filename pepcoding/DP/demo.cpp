#include <bits/stdc++.h>
using namespace std;
int main() {

int t ; cin>>t;
while(t--) { 
    int m,n;
    cin>>m>>n;
    int arr[m][n];
    for(int i=0; i<m; i++ ) {
        int k = 0; 
        for ( int j=0; j<n; j++ ) {
            cin>>arr[i][j];
        }
    }
    for(int i=0; i<m; i++ ) {
        int k = 0; 
        for ( int j=0; j<n; j++ ) {
            cout<<arr[i][j];
        }
    } 
}

}


