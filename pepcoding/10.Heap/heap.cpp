#include <bits/stdc++.h>
using namespace std;

class Heap {

    private:
        void heapify(int idx){

        int  l = 2 * idx;
        int  r = l +   1;
        int mx = idx;

        if( l < arr.size() && arr[l] > arr[mx])
            mx = l;
        
        if( r < arr.size() && arr[r] > arr[mx])
            mx = r;

        if( mx != idx){
           swap(arr[idx],arr[mx]);

           heapify(mx);

        }
        }

    public:
    vector<int> arr;
    int size = 0;

    Heap ( int n){
        arr.resize(n);
        size = n;
        arr[0] = -1;

    }

    void push ( int data) {
        arr.push_back(data);

        int idx = arr.size() -1;
        while( idx > 1 && arr[idx] > arr[idx/2]){
            swap(arr[idx],arr[idx/2]);
            idx = idx / 2;
        }
    }

    int top(){
        return arr[1];
    }

    void pop() {
        swap(arr[1], arr[size -1]);

        if(!arr.empty()){
            heapify(1);
        }
        
    }

    bool empty() {
        return arr.size() == 1;
    }
};

int main() {


    vector<int> arr = { 3,3,34,3,42,2345,343,6,34};
    Heap h(arr.size());

    for( int i=0; i<arr.size(); i++){
        h.push(arr[i]);
    }

    for( int i =0; i<arr.size();i++){
        cout<<h.top()<<" ";
        h.pop();
    }

    return 0;
}