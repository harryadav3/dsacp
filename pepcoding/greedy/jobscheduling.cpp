#include <bits/stdc++.h>
using namespace std;
/*
Given a set of N jobs where each jobi has a deadline and profit associated with it.

Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit associated with job if and only if the job is completed by its deadline.

Find the number of jobs done and the maximum profit.

Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job. Deadline of the job is the time before which job needs to be completed to earn the profit.

1 <= N <= 105
1 <= Deadline <= N
1 <= Profit <= 500

vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
    } 

    solve this question by sorting on deadline and the use min-heap to solve this question
*/

    //solve this question by sorting on deadline and the use min-heap to solve this question

    struct Job {
        int id, dead, profit;
    };

void compare

vector<int>  JobScheduling(Job arr[], int n) 
    { 
        // your code here
        // sort(arr, arr+n, [](Job a, Job b) {
        //     return a.dead < b.dead;
        // });

        sort( arr, arr+n, compare);
        
        priority_queue<int, vector<int>, greater<int>> pq;
        int count = 0, profit = 0;
        for(int i = 0; i < n; i++) {
            if(pq.size() < arr[i].dead) {
                pq.push(arr[i].profit);
                count++;
                profit += arr[i].profit;
            } else {
                if(pq.top() < arr[i].profit) {
                    profit -= pq.top();
                    pq.pop();
                    pq.push(arr[i].profit);
                    profit += arr[i].profit;
                }
            }
        }
        
        return {count, profit};
    }


    //solve this question by sorting on profit and the use max-heap to solve this question

    struct Job {
        int id, dead, profit;
    };
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr, arr+n, [](Job a, Job b) {
            return a.profit > b.profit;
        });
        
        priority_queue<int> pq;
        int count = 0, profit = 0;
        for(int i = 0; i < n; i++) {
            if(pq.size() < arr[i].dead) {
                pq.push(arr[i].dead);
                count++;
                profit += arr[i].profit;
            } else {
                if(pq.top() < arr[i].profit) {
                    profit -= pq.top();
                    pq.pop();
                    pq.push(arr[i].profit);
                    profit += arr[i].profit;
                }
            }
        }
        
        return {count, profit};
    }



    //solve this question by sorting on profit and the use array to solve this question

    struct Job {
        int id, dead, profit;
    };

    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr, arr+n, [](Job a, Job b) {
            return a.profit > b.profit;
        });
        
        int maxDeadline = 0;
        for(int i = 0; i < n; i++) {
            maxDeadline = max(maxDeadline, arr[i].dead);
        }
        
        vector<int> slots(maxDeadline+1, -1);
        int count = 0, profit = 0;
        for(int i = 0; i < n; i++) {
            for(int j = arr[i].dead; j >= 1; j--) {
                if(slots[j] == -1) {
                    slots[j] = i;
                    count++;
                    profit += arr[i].profit;
                    break;
                }
            }
        }
        
        return {count, profit};
    }


    //solve this question by sorting on deadline and the use array to solve this question
     
vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr, arr+n, [](Job a, Job b) {
            return a.profit > b.profit;
        });
        
        int maxDeadline = 0;
        for(int i = 0; i < n; i++) {
            maxDeadline = max(maxDeadline, arr[i].dead);
        }
        
        vector<int> slots(maxDeadline+1, -1);
        int count = 0, profit = 0;
        for(int i = 0; i < n; i++) {
            for(int j = arr[i].dead; j >= 1; j--) {
                if(slots[j] == -1) {
                    slots[j] = i;
                    count++;
                    profit += arr[i].profit;
                    break;
                }
            }
        }
        
        return {count, profit};
    }


int main() {

    

    return 0;
}


/*

class Task {
    name,
    deadline, 
    money,
    
}
*/