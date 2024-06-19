#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int s, int e){
    int pivot = arr[e];
    int i = s-1;
    for(int j=s; j<e; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[e]);
    return i+1;
}
void quicksort(vector<int>& arr, int s , int e){
    if( s > e){
        return;
    }

    int pi = partition(arr, s, e);
    quicksort(arr, s, pi-1);
    quicksort(arr, pi+1, e);

}

int getRandom(int a, int b){
    return (rand() % (b-a+1)) + a;
}

int randomShufflearr( vector<int>& arr){
    
    for(int i=arr.size()-1; i>0; i--){
        int j = getRandom(0, i);
        swap(arr[i], arr[j]);
    }
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    return 0;
}

int quickselect(vector<int> v,int  s, int  e , int  k){
    if( s > e){
        return -1;
    }

    int pi = partition(v, s, e);
    if( pi == k){
        return v[pi];
    }
    else if( pi >  k) {
        return quickselect(v, s, pi-1, k);
    }
    else {
        return quickselect(v, pi+1, e, k);
    }
}

int main() {

    vector<int> v = {23, 45, 12, 67, 34, 90, 6};
    int n = v.size() - 1;
   // quicksort(v, 0, v.size()-1);

   
    // randomShufflearr(v);
   
   cout<<quickselect(v, 0, n, n - 2)<<endl;



    return 0;
}