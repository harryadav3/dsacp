#include <bits/stdc++.h>
using namespace std;

    bool canPlace( int c , int n , vector<int> stalls, int sep){
        int cows = 1;
    int last_cow = stalls[0];
        for ( int i = 1; i<n; i++){
            if( stalls[i] - stalls[i-1] >= sep){
                cows++;
                last_cow = stalls[i];
                if( cows == c){
                    return true;
                }
            }
        }
        return false;
    }
int main() {
   int N=5 ;
    int C=3;
    vector<int> stalls =  { 1,2, 4,8, 9} ;
    
    sort(stalls.begin(), stalls.end());
    int n = stalls.size();
    int s = 0, e = stalls[n-1] - stalls[0];
    int ans = 0;


    while ( s <= e){
        int mid = ( s + e ) / 2;

        if( canPlace( C , N , stalls, mid)){
            ans = mid ;
            s = mid + 1;
        }
         else {
            e = mid -1;
         }
    }

    cout<<ans<<endl;

    return 0;
}