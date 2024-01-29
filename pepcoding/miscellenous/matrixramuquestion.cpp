#include <bits/stdc++.h>
using namespace std;


int main() {

    int n = 4;
    int man[n][n] = {{1,2,3,1},
               {2,6,4,8},
               {1,3,2,7},
               {2,0,1,5}};
    int ans = 0;
    int s[4][4] = {
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0}
    };
    
    s[0][0] = man[0][0];
    for ( int i =1; i < n; i++){
        s[i][0] = man[i][0] + s[i-1][0];
    }
    for ( int j = 1; j< n; j++ ) {
        s[0][j] = man[0][j] + s[0][j-1];
    }

    for( int i = 1; i < n; i++) {
        for ( int j = 1; j<n; j++){
            

            
            s[i][j] = s[i][j-1] + s[i-1][j] - s[i-1][j-1] + man[i][j];
        

        }
    }


for( int i=0;i<n; i++){
    for ( int j=0; j<n; j++) {
        cout << s[i][j] << " ";
    }
    cout<<endl;
}

    for( int i =0; i <= n-2; i++){
        for ( int j =0; j<=n -2; j++){
            int q1 = s[i][j];
            int q2 = s[i][n-1] - q1;
            int q3 = s[n-1][j] - q1;
            int q4 = s[n-1][n-1] - ( q1 + q2 + q3 );

            int ramu = min(q1,min(q2,min(q3,q4)));

            ans = max(ans, ramu);
        }
    }

    cout<<"Answer is " << ans << endl;
    return 0;
}