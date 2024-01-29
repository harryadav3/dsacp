#include <bits/stdc++.h>
using namespace std;

// bool canCut( int mid, int n, vector<int> coins){
//     int sum = 0;
//     // for ( int i = 0; i < n; i++){
//     //     sum += coins[i] / mid;
//     // }
//     // 
// return sum >= n;

//         int cut = 0;
//     for ( int i =0; i<n; i++){
//         sum += coins[i] ;
//         if( sum >= n){
//             cut++;
//             sum = 0;
//         }
    
//     }
//     if ( cut >= mid ) {
//         return true;
//     }

//     return false;
// }

bool check ( vector<int> nums, int k, int thsd){
    int n = nums.size();

    int count = 0;
    int csum =0;

    for (int i=0; i<n; i++){
        if( csum , thsd){
            csum += nums[i];
        }
        else {
            csum = nums[i];
            count++;
        }
    }

    if( csum > thsd){
        count++;
    }

    return count >= k;
}
int main() {
//Absolute books
    
    vector<int> coins = {6,8,4,2,1,7};
    int n = coins.size();
    int k = 3; 
    int s = *min_element(coins.begin(), coins.end() );
    int  e = accumulate(coins.begin(), coins.end(),0);

    int ans = s;
    while( s<= e) {

       int  mid = ( s + e ) /2;

        if( check(coins, k, mid)){
            ans = mid;
            s = mid + 1;
        } else {
            e = mid -1;
        }
    }

    cout<<ans<<endl;
    return 0;
}