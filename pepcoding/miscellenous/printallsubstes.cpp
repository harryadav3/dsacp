#include <bits/stdc++.h>
using namespace std;

   vector<vector<int>> subsets(int i, int n,vector<int> nums) {
        // int n = nums.size(), p = 1 << n;
        int p = 1 << n;
        vector<vector<int>> subs(p);


        for ( i = 0; i < p; i++) {

            for (int j = 0; j < n; j++) {

                if ((i >> j) & 1) {
                    subs[i].push_back(nums[j]);
                }
            }
        }
        return subs;
    }

int main() {

    vector<int> nums = {1,2,3,0,5,6,-2,8}; 

    int n = nums.size();
    int d = n/2;
    int sum1 = 7;
    int sum2 = 12;

    vector<vector<int>> subs1 = subsets(0,d, nums);
    vector<vector<int>> subs2 = subsets(d,n,nums);

    sort(subs2.begin(), subs2.end());

    for (int i = 0; i < subs1.size(); i++) {
      
      
    }



    return 0;
}