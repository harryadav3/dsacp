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
void insertion_sort(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int key = arr[i];
        // in the below method using for loop there is a problem because j cannot be used outside the second for loop hence a while loop is required to implement the insertion sort
        /*
        for (int j = i; j > 0; j--)
        {
            if (arr[j] < arr[j - 1])
                arr[j] = arr[j - 1];
        }
        arr[j] = key;
        */
        int j = i;
        while (j > 0 && arr[j - 1] > key)
        {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = key;
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
    insertion_sort(arr, size);
    display(arr, size);
    return 0;
}