#include <bits/stdc++.h>
using namespace std;

bool canCook( vector<int>& arr, int p,int n, int mid){
    int total = 0;
    for ( int c : arr){
        int count = 0,
        int rank = c;
        int ctime = 0;
        while( ctime + (count+1)*rank <= mid){
            count++;
            ctime += ctime + count * rank;
            
        }
        total += count;
    }
    return total >= p;
}

int main() {

    int p = 10;
    vector<int> arr = {1,2,3,4};
    int n = arr.size();
    int s = 0 , e = 55;
    int ans = 0;

    while ( s <= e){

        int mid  =( s + e) /2 ;

        if( canCook(arr,p,n, mid)){
            ans = mid;
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }
    cout<<ans<<endl;

    return 0;
}