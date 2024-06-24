

#include <bits/stdc++.h>
using namespace std;


/*
Given an input stream of N integers. The task is to insert these numbers into a new stream and find the median of the stream formed by each insertion of X to the new stream.

N = 4
X[] = 5,15,1,3
Output:
5
10
5
4
Explanation:Flow in stream : 5, 15, 1, 3 
5 goes to stream --> median 5 (5) 
15 goes to stream --> median 10 (5,15) 
1 goes to stream --> median 5 (5,15,1) 
3 goes to stream --> median 4 (5,15,1 3) 


solve this question using min heap and max heap concept

using this class 
class Solution
{
    public:
    //Function to insert heap.
    void insertHeap(int &x)
    {
        
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        
    }
    
    //Function to return Median.
    double getMedian()
    {
        
    }
};

*/

class Solution
{
    public:
    //Function to insert heap.
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    void insertHeap(int &x)
    {
        if(maxHeap.size() == 0 || x < maxHeap.top()) {
            maxHeap.push(x);
        } else {
            minHeap.push(x);
        }

        if(maxHeap.size() - minHeap.size() == 2) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if(minHeap.size() - maxHeap.size() == 2) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    
    void balanceHeaps()
    {
        // Your code here
        if(maxHeap.size() - minHeap.size() == 2) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if(minHeap.size() - maxHeap.size() == 2) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }


    double getMedian()
    {
        // Your code here
        if(maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        } else if(maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        } else {
            return minHeap.top();
        }
    }

};


void runningMedian(int arr[], int n) {
    // min heap
    priority_queue<int, vector<int>, greater<int>> minHeap;
    // max heap
    priority_queue<int> maxHeap;

    for(int i = 0; i < n; i++) {
        if(maxHeap.size() == 0 || arr[i] < maxHeap.top()) {
            maxHeap.push(arr[i]);
        } else {
            minHeap.push(arr[i]);
        }

        if(maxHeap.size() - minHeap.size() == 2) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if(minHeap.size() - maxHeap.size() == 2) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        if(maxHeap.size() == minHeap.size()) {
            cout << (maxHeap.top() + minHeap.top()) / 2 << endl;
        } else if(maxHeap.size() > minHeap.size()) {
            cout << maxHeap.top() << endl;
        } else {
            cout << minHeap.top() << endl;
        }
    }
}


int runningMedian2 ( ) {
    int n;
    cin >> n;
     priority_queue<int, vector<int>, greater<int>> minHeap;
    // max heap
    priority_queue<int> maxHeap;

 
    vector<int> v(n);

    vector<int> ans(n);
    ans[0] = v[0];
    int median = ans[0];
    maxHeap.push(v[0]);

    for(int i = 1; i < n; i++) {
        cin >> v[i];
        if(v[i] < median) {
            maxHeap.push(v[i]);
        } else {
            minHeap.push(v[i]);
        }


       int x = maxHeap.size() ;
       int y = minHeap.size();

       if( abs(x - y) > 1) {
           if(x > y) {
               minHeap.push(maxHeap.top());
               maxHeap.pop();
           } else {
               maxHeap.push(minHeap.top());
               minHeap.pop();
           }

          if(maxHeap.size() == minHeap.size()) {
            median = (maxHeap.top() + minHeap.top()) / 2;
        } else if(maxHeap.size() > minHeap.size()) {
            median = maxHeap.top();
        } else {
            median = minHeap.top();
        }



        ans[i] = median;
    }

}
int main() {

    

    return 0;
}