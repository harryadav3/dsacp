#include <bits/stdc++.h>
using namespace std;

int main() {

    int arr[] = { 100, 80, 120 , 70 , 60 , 75, 85};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> ans;


    stack<int> s ;
    s.push(0);

    for(int i=0; i<n; i++){

        while(!s.empty() and arr[i] > arr[s.top()]) {
                s.pop();
        }

        if(s.empty() ){
            ans.push_back(i - s.top() + 1);
        }else {
            ans.push_back(i-s.top() + 1);
        }

        s.push(i)
    }

    return 0;
}