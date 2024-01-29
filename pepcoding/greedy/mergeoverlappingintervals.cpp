#include <bits/stdc++.h>
using namespace std;



vector<vector<int>>  merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        if(intervals.size() == 0) return ans;
        sort(intervals.begin(), intervals.end());
        vector<int> temp = intervals[0];
        for(auto it : intervals) {
            if(it[0] <= temp[1]) {
                temp[1] = max(it[1], temp[1]);
            } else {
                ans.push_back(temp);
                temp = it;
            }
        }
        ans.push_back(temp);
        return ans;
    }
    
    // Path: pepcoding/greedy/mergeoverlappingintervals.cpp
    // Compare this snippet from pepcoding/greedy/jobscheduling.cpp:
    //     };
    // 
    //     vector<int> JobScheduling(Job arr[], int n) 
    //     { 
    //         // your code here
    //         sort(arr, arr+n, [](Job a, Job b) {
    //             return a.profit > b.profit;
    //         });
    //         
    //         int maxDeadline = 0;
    //         for(int i = 0; i < n; i++) {
    //             maxDeadline = max(maxDeadline, arr[i].dead);
    //         }
    //         
    //         vector<int> slots(maxDeadline+1, -1);
    //         int count = 0, profit = 0;
    //         for(int i = 0; i < n; i++) {
    //             for(int j = arr[i].dead; j >= 1; j--) {
    //                 if(slots[j] == -1) {
    //                     slots[j] = i;
    //                     count++;
    //                     profit += arr[i].profit;
    //                     break;
    //                 }
    //             }
    //         }
    //         
    //         return {count, profit};
    //     }
    // 
    // 
    //     //solve this question by sorting on deadline and the use array to solve this question
    //      
    // vector<int> JobScheduling(Job arr[], int n) 
    //     { 
    //         // your code here
    //         sort(arr, arr+n, [](Job a, Job b) {
    //             return a.profit > b.profit;
    //         });
    //         
    //



int main() {

    

    return 0;
}