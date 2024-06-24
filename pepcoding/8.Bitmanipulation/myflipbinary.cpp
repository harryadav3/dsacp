#include <bits/stdc++.h>
using namespace std;

int powof( int ind) {
    
    return 1<<ind;
}
// int powof2( int ind) {
//     int ans = 1;
//     for (int i = 0; i < ind; i++) {
//         ans = ans * 2;
//     }
//      return ans;
// }

int main() {

    int n = 51;

    int x = 0; int ind = 0;
    while( n > 0 ) {

        if( ( n & 1 ) == 0) {
            x += powof(ind);
        }
        n = n >> 1; // Fix: Added the increment operator to update the value of n after right-shifting it.
        ind++;
    }

    cout<< x << endl;
    return 0;
}