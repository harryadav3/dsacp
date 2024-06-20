#include <iostream>

using namespace std;

int find_pivot(int arr[], int n) {

    if(arr[0] > arr[1]){
        return 1;
    }
    if(arr[n-1] < arr[n-2]){
        return n-1;
    }
  int left = 1;
  int right = n-2;


  while (left <= right) {
    int mid = (left + right) / 2;
    
    if( arr[mid] < arr[mid -1] && arr[mid] < arr[mid + 1]){
        return mid;
    }
    // if ( arr[mid] > arr[mid+1] && arr[mid] >  arr[mid - 1]){
    //     return mid + 1;
    // }

   else  if (arr[mid] > arr[left] && arr[mid] < arr[right]) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }

    
  }

  return -1;
}

int main() {
  int arr[] = {5, 6, 7,8, 1, 2, 3, 4};
  int n = sizeof(arr) / sizeof(arr[0]);

  int pivot = find_pivot(arr, n);

  cout << "The pivot is at index " << arr[pivot] << endl;

  return 0;
}