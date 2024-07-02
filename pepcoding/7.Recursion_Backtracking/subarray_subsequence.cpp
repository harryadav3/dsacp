

/*

Subarray - is a contiguous part of an array 
eg: [1,2,3] => [1], [1,2], [1,2,3], [2], [2,3], [3]


Subsequence - is a sequence that can be derived from an array by selecting zero or more elements, without changing the order of the remaining elements.

eg: [1,2,3] => [1], [1,2], [1,2,3], [1,3], [2], [2,3], [3], []


*/

#include <bits/stdc++.h>
using namespace std;


void solve(vector<int> &nums , int n , vector<vector<int>> &ans){

    for( int n = 0; n < (int) pow(2, nums.size()); n++) {
        vector<int> temp;
        for( int i = 0; i < nums.size(); i++) {
            if( n & (1 << i)) {
                temp.push_back(nums[i]);
            }
        }
        ans.push_back(temp);
    }

}

int main() {

    vector<int> nums = {1,2,3};
    vector<vector<int>> ans;
    solve(nums, 0, ans);

    for( auto v : ans) {
        for( auto x : v) {
            cout<<x<<" ";
        }
        cout<<endl;
    }    

    return 0;
}