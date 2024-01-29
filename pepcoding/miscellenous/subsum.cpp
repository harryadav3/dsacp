#include <bits/stdc++.h>
using namespace std;

void subsets( vector<int> &arr , vector<int>&v, int start, int end){

    int n = end - start + 1;

    for ( int i = 0; i < (1 << n); i++) {

        int  j =0, sum = 0, int k=i;

        while( k ) {
            if( k & 1) {
                sum+= arr[start + j];
            }

            k>>1;
            j++;
        }
        v.push_back(sum);
    }
}

int main() {

    int  a , b;
    cin>>a>>b;
    vector<int> arr = { 1,2, 3,0, 6 ,4 ,8};
    int n = arr.size();

    vector<int> ans; 
    vector<int> left, right;

    subsets(arr, left, 0, n/2);
    subsets(arr, right, n/2 + 1, n-1);

    sort(right.begin(), right.end());
    int ans = 0;
    for ( int x: left) {
        // int y = b - x;
        // auto it1 = lower_bound(right.begin(), right.end(), y);
        // auto it2 = upper_bound(right.begin(), right.end(), y);

        // for ( auto it = it1; it != it2; it++) {
        //     ans.push_back(x + *it);
        // }

        int ub = upper_bound(right.begin(), right.end(), b - x) - right.begin();
        int lb = lower_bound(right.begin(), right.end(), b - x) - right.begin();

        
    }

    cout<<ans;

    return 0;
};