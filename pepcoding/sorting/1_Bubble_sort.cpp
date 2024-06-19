// bubble sort : compare adjacent elements and swap
#include <iostream>
#include <vector>
#include <algorithm> // Add missing header for std::swap
using namespace std;
void BubbleSort_asc(vector<int>& v) // Modify function to take vector by reference
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i; j < v.size() - 1; j++)
        {
            if (v[j] > v[j + 1])
                swap(v[j], v[j + 1]);
            for (int k : v)
            {
                cout << k << " ";
            }
            cout << endl;
        }
    }
}

void bubble_sort_arr( int arr[] , int n) {

    for ( int i=0; i<n;i++) {

        for( int j=0; j < n - 1 ; j++ ) {

            if ( arr[j] > arr[j + 1]) {
                swap(arr[j] , arr[j + 1]);
            }
        }

    }
}

// Apar kamal solution for bubble sort bringing the smallest element to the front
// it i sin place sorting
// it is stable
boid bubble_sort_masab( int a[] , int n ) {
    int sc = 1;

    while( sc) {
        sc = 0;
        for( int i= n - 2; i >=0 ; i--) {
            if ( a[i] > a[i + 1]) {
                swap(a[i] , a[i + 1]);
                sc = 1;
            }
        }
    }
    
}
int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(7);
    v.push_back(6);
    v.push_back(10);
    v.push_back(9);
    v.push_back(14);
    // BubbleSort_asc(v);
    int arr[] = {1, 7, 6, 10, 9, 14};
    bubble_sort_arr(arr, 6);
    for (int i : arr)
    {
        cout << i << " ";
    }
    return 0;
}
