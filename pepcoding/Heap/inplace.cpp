#include <bits/stdc++.h>
using namespace std;

void maxheapify(vector<int> &arr, int idx){
    int l = 2 * idx + 1;
    int r = 2 * idx + 2;
    int mx = idx;
    if( l < arr.size() && arr[l] > arr[mx]){
        mx = l;
    }
    if( r < arr.size() && arr[r] > arr[mx]){
        mx = r;
    }
    if( mx != idx){
        swap(arr[idx], arr[mx]);
        maxheapify(arr, mx);
    }
    
}

void buildheap(vector<int> &arr){
    int n = arr.size();
    for(int i = arr.size() - 1; i >= 0; i--){
           maxheapify(arr, i);
    }
}

int main() {

    vector<int> v = {32,45,82,923,43,56,67,87,891};


    return 0;
}