#include <bits/stdc++.h>
using namespace std;

// 'n' = 3, 'w' = 10, 
// 'profit' = [5, 11, 13]
// 'weight' = [2, 4, 6]*/


int main() {

    int n = 3;
    int w = 10;
    vector<int> profit = {5, 11, 13};
    vector<int> weight = {2, 4, 6};

    vector<vector<int>> dp( n , vector<int> ( w + 1, 0) );

    // for( int i =0 ; i<=w; i++) dp[0][i] = (( w/weight[i]) * profit[i]);

    for( int i = 0 ; i<= w; i++ ) {
        dp[0][i] = (( (int) i/weight[0]) * profit[0]);
    }

    // print dp array
    for ( int i = 0 ; i<n; i++ ) {
        for ( int j = 0 ; j<=w; j++ ) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
 
    for ( int ind=1; ind<n; ind++ ) {

            for ( int j= 0 ; j<=w; j++ ) {


                    // if( dp[ind][w] != -1) return dp[ind][w];
                    int notTake = dp[ind - 1][j] ;

                    int take = 0;

                    if(weight[ind] <= j) {
                        take = profit[ind] +  dp[ind][ j - weight[ind]];
                    }

                    dp[ind][j] = max( take , notTake);


            }
    }
    cout<<"_______________________________\n";
    //print dp array
    for ( int i = 0 ; i<n; i++ ) {
        for ( int j = 0 ; j<=w; j++ ) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<dp[n-1][w]<<endl;
    return 0;
}