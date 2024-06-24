#include <bits/stdc++.h>
using namespace std;


/*
There are n jobs that can be execute in paralle on a processorw hwere teh execution time of the ith jjob is execution time ot speed upexecution the folowing sragety is  used in one operation a jobs i chosen the major job and a executed for a secons All other jobs are executued for y seconds where y<x A jobs is compltere whern it has beenn ececuted for at least executionTime() seconds then it exits the pool fin th eminum number of operation in whihc the processor can completerly ececture all teh jobs if run optimall 

Exmaple;
Cosnider n = 5, executionTime = { 3,4,1,7,6,] x = 4 and y= 2

The folowwing stratesgy is optimal using 1 based indexing Chose job 4 as the major job and reduce the execution tiems of job 4 by x = 4 and ofother jobs by y = 2 Now executionTime = [ 1,2,-1,3,4] jobs 3 is complete so it is remove 

Chose jobs 4 executiontime = [-1,0,-1,3,4] jobs 3 is complet so it is removed
Choose job 4 , execution time = [-1,0,-,-1,2] os jobs 1,2,and 4 are now completer choose job 45 executionime = [-,-,-,-,-,-1] job 5 is compler 


it take 3 operation to execute all the jobs so answer is 3

compler the function get minimum operation for this question 

constraints = 1 <= n <= 10^5
1 <= executionTime(i) <=109
1 <=y<=x<=109

sample case : 1 

n = 5
execturiontimp[] = { 3,3,6,3,9]
x = 3
y = 2
ans = 3
int getMininumOperations(int executedTime_count, vection<int> nums, int x, int y){
}

complete this function to solve the given problem c++ 
*/


bool isPossible(int mid, std::vector<int>& executionTime, int x, int y) {
    long long total = 0;
    for (int i = 0; i < executionTime.size(); i++) {
        total += (executionTime[i] + x - 1) / x;
        if (total > mid) {
            return false;
        }
    }
    return true;
}


int getMinimumOperations2(int n, std::vector<int>& executionTime, int x, int y) {
  
      sort(executionTime.begin(), executionTime.end());
    int left = 1, right = 1e9;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (isPossible(mid, executionTime, x, y)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
 
}

int getMinimumOperationsbard(int n, std::vector<int>& executionTime, int x, int y) {
    // Sort the jobs in descending order of execution time.
    vector<pair<int, int>> jobs(n);
    for (int i = 0; i < n; ++i) {
        jobs[i] = {i, executionTime[i]};
    }
    sort(jobs.begin(), jobs.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    });

    // Initialize the number of operations and remaining time for each job.
    int operations = 0;
    vector<int> remainingTime(n);
    for (int i = 0; i < n; ++i) {
        remainingTime[i] = jobs[i].second;
    }

    while (any_of(remainingTime.begin(), remainingTime.end(), [](int time) { return time > 0; })) {
        // Choose the job with the most remaining time as the major job.
        int majorJobIndex = 0;
        for (int i = 1; i < n; ++i) {
            if (remainingTime[i] > remainingTime[majorJobIndex]) {
                majorJobIndex = i;
            }
        }

        // Execute the major job for x seconds.
        remainingTime[majorJobIndex] = max(0, remainingTime[majorJobIndex] - x);

        // Execute other jobs for y seconds.
        for (int i = 0; i < n; ++i) {
            if (i != majorJobIndex) {
                remainingTime[i] = max(0, remainingTime[i] - y);
            }
        }

        // Count the number of completed jobs.
        int completedJobs = 0;
        for (int i = 0; i < n; ++i) {
            if (remainingTime[i] == 0) {
                ++completedJobs;
            }
        }

        // Update the number of operations based on completed jobs.
        operations += completedJobs;

        // Remove completed jobs from the list.
        jobs.erase(remove_if(jobs.begin(), jobs.end(), [](const pair<int, int>& job) { return job.second == 0; }), jobs.end());
    }

    return operations;
}


int getMinimumOperationsgpt(int n, vector<int>& arr, int x, int y) {
       std::priority_queue<int> pq;

    for (int i = 0; i < n; i++) {
        pq.push(arr[i]);
    }

    int operations = 0;

    while (true) {
        // Since past number of operations were not enough, doing another operation
        operations++;

        // Decremented the top element by an extra amount of (x - y)
        int num = pq.top();
        pq.pop();
        num -= (x - y);

        // Pushed after decrementing
        pq.push(num);

        // Now again finding the current maximum of the array and applying y decrements the number of times operations has occurred
        int curr = pq.top();
        curr -= (operations * y);

        // If the maximum got negative, then for sure others would have got negative or zero
        if (curr <= 0) break;
    }

    return operations;
}
int main() {

    int n= 5;
    vector<int> executionTime = { 3,3,6,3,9};
    int x = 3;
    int y = 2;
    cout<<getMinimumOperations2(n, executionTime, x, y)<<endl;
    cout<<getMinimumOperationsgpt(n , executionTime, x, y)<<endl;
    cout<<getMinimumOperationsbard(n , executionTime, x, y)<<endl;

    return 0;
}