// Merge sort: Divide the array into two parts like in binary search. Use recursion to keep dividing the arrays. Merge the divided arrays in the sorted form recursively to get the entire sorted array. This sorting algorithm is faster than bubble sort, insertion sort and selection sort. It has the same time complexity (O(nlogn)) for all three cases best, avg, worst. It has a space complexity of O(n).
#include <iostream>
using namespace std;
void merge(int *arr, int start, int end)
{
    int mid = start + (end - start) / 2;

    // creating the size of the new arrays
    int size1 = mid - start + 1;
    int size2 = end - mid;

    int *arr1 = new int[size1];
    int *arr2 = new int[size2];

    // adding the values to the new arrays (sorted)
    int mainidx = start;
    for (int i = 0; i < size1; i++)
        arr1[i] = arr[mainidx++];

    mainidx = mid + 1;
    for (int i = 0; i < size2; i++)
        arr2[i] = arr[mainidx++];

    // merging the two sorted arrays
    int idx1 = 0;
    int idx2 = 0;
    mainidx = start;

    while (idx1 < size1 and idx2 < size2)
    {
        if (arr1[idx1] < arr2[idx2]) // to sort in descending order check (if arr[idx1] > arr[idx2])
            arr[mainidx++] = arr1[idx1++];
        else
            arr[mainidx++] = arr2[idx2++];
    }
    while (idx1 < size1)
        arr[mainidx++] = arr1[idx1++];
    while (idx2 < size2)
        arr[mainidx++] = arr2[idx2++];
    // freeing the memory after usage
    delete[] arr1;
    delete[] arr2;
}

void merge_sriver(int arr[], int low , int mid, int high) {
    // temp arr
    int temp[high - low + 1];
    int left = low , right = mid + 1;


    // merging the two arrays

    while( left <= mid && right <= high) {
        if( arr[left] <= arr[right]) {
            temp[left++] = arr[left++];
        } else {
            temp[left++] = arr[right++];
        }
    }

    // copying the remaining elements of the left array

    while (left <= mid) {
       temp[left++] = arr[left++];
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp[left++] = arr[right++];
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i];
    }
}   
}
void mergesort(int *arr, int start, int end)
{
    // base case
    if (start >= end)
        return;
    int mid = start + (end - start) / 2;
    mergesort(arr, start, mid);   // sorting the left part
    mergesort(arr, mid + 1, end); // sorting the right part

    // merging the sorted parts
    merge(arr, start, end);
}
int main()
{
    int size = 0;
    cin >> size;
    int *arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << endl;
    cout << "before sorting" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "\t";
    }
    mergesort(arr, 0, size - 1); // calling the sorting function
    cout << endl;
    cout << "after sorting" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "\t";
    }
    return 0;
}