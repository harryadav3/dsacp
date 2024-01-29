// the selection sort algorithm
// sort the array by repeatedly finding the minumum element in the array (jth element) and swapping it with the ith element
#include <iostream>
#include <algorithm>
using namespace std;
void display(int *arr, int size)
{
    cout << "the elements of the array are : ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void selection_sort(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int mini = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[mini])
                mini = j;
        }
        swap(arr[i], arr[mini]);
    }
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
    display(arr, size);
    selection_sort(arr, size);
    display(arr, size);
    return 0;
}