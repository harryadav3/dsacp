

#include <bits/stdc++.h>
using namespace std;

// base of system 
// the idea is to do the sorting on the bassis of place value or the bases 
/*


2 22 597 556 497 10 3 


after first pass

10 2 22 3 497 597 556
we will assume the 1's place value is 0 if the number is less than the place value
10 02 22 03 497 597 556

after second pass

02 03 10 22 497 556 597

now we will assume the 10's place value is 0 if the number is less than the place value

002 003 010 022 497 556 597

after third pass

002 003 010 022 497 556 597

*/


void radix_sort( int a[], int n ) {
    // find the maximum element in the array
    int max = *max_element(a, a+n);
    // find the number of digits in the maximum element
    int digits = 0;
    while( max > 0 ) {
        max /= 10;
        digits++;
    }
    // create the buckets
    vector<int> bucket[10];
    // iterate over the number of digits
    for( int i = 0; i < digits; i++ ) {
        // iterate over the array
        for( int j = 0; j < n; j++ ) {
            // find the place value of the number
            int place = a[j] / pow(10, i);
            // find the digit at the place value
            int digit = place % 10;
            // push the number in the bucket
            bucket[digit].push_back(a[j]);
        }
        // clear the array
        int idx = 0;
        for( int j = 0; j < 10; j++ ) {
            for( int k = 0; k < bucket[j].size(); k++ ) {
                a[idx++] = bucket[j][k];
            }
            bucket[j].clear();
        }
    }

}
int getMaxLevel(int a[], int n ) {
    int mx = 0;
    for( int i=0; i<n;i++) {
        string  s= to_string(a[i]);
        mx= max(mx, (int)s.size());
    }

    return mx;
}

void countRadixSort(int a[], int n , int level) {
    vector<int> cnt[10];
    
    for( int i=0; i<n; i++ ) {
        int digit =  ( a[i] / (int)pow(10,level)) % 10;
        cnt[digit].push_back(a[i]);
    }

    for( int i=0, k=0; i<10; i++) {
        for ( int x: cnt[i]) {
            a[k] = x;
            k++;
        }
        }
}
void radix_sort_masab(int a[] , int n ) {
    int maxLevel = getMaxLevel(a,n);

    for( int i=0; i<= maxLevel; i++ ) {

        countRadixSort(a,n,i);
    }

}

int main() {
    // int a[] = { 2, 22, 597, 556, 497, 10, 3};
    // int a[] = { 8 , 6 , 2 , 4, 7};
    int a[] = { 88 , 25, 72, 63, 91, 29 };
    int n = sizeof(a)/sizeof(a[0]);

    radix_sort(a,n);

    for( int i=0; i<n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}