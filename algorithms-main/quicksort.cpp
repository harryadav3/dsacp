/*
// Quick Sort
In Quick Sort an element is selected and placed in its right place in the final sorted array. all the elements to the left of the selected elements will be smaller or equal to and all the elements to the right will be greater than or equal to. This is called as partioning.

Quick sort : Start from the leftmost element and keep track of the index of smaller (or equal to) elements as i. While traversing, if we find a smaller element, we swap the current element with arr[i]. Otherwise, we ignore the current element.

pseudo code
partition (array , start, end)
{
    pivot = end element
    one pointer at the start (j) and one before it (i)
    iterate j till p - 1 (second last element)
        if arr[j] <= pivot
            i++;
            swap arr[j], arr[i];
        if arr[j] > pivot
            j++;
    swap arr[j], arr[[pivot]]
}
quicksort (array, start ,end)
{
    //base case
    if (start >= end)
        return;
    // partitioning
    pivot = partition(array, start, end);
    // recursion
    quicksort (arr, start, pivot - 1);
    quicksort (arr, pivot + 1, end);
}
*/

#include <iostream>
using namespace std;
int partition(int *arr, int start, int end)
{
    int pivot = arr[end]; // setting the pivot to the last element
    int i = start - 1;
    int j = start;
    for (j; j < end; j++)
    {
        if (arr[j] <= pivot)
        {
            // if the current element is less than or equal to the pivot then increment i and swap the elements at i and j
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[j]); // putting the pivot element in its correct place in the final sorted array
    return (i + 1);           // returning the index at where the pivot element is located in the final sorted array
}
void quicksort(int *arr, int start, int end)
{
    if (start >= end)
        return;
    if (start < end)
    {
        // finding the partition
        int partitionidx = partition(arr, start, end);
        // sorting the elements to the left of the partition
        quicksort(arr, start, partitionidx - 1);
        // sorting the elements to the right of the partition
        quicksort(arr, partitionidx + 1, end);
    }
}
int main()
{
    int size = 0;
    cout << "enter the size of the array : ";
    cin >> size;
    // allocating memory dynamically for the array
    int *arr = new int[size];
    // taking input in the array
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    cout << endl;
    // printing the array before sorting
    cout << "before sorting: " << endl;
    for (int i = 0; i < size; i++)
        cout << arr[i] << "\t";
    // applying quicksort to sort the array
    quicksort(arr, 0, size - 1);
    cout << endl;
    // printing the final sorted array
    cout << "after sorting: " << endl;
    for (int i = 0; i < size; i++)
        cout << arr[i] << "\t";
    return 0;
}