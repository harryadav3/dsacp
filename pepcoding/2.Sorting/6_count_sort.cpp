

// count sort


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


void count_sort(int *arr, int size)
{
    int max = *max_element(arr, arr + size);
    int min = *min_element(arr, arr + size);
    int range = max - min + 1;
    int *count = new int[range];
    int *output = new int[size];
    for (int i = 0; i < range; i++)
    {
        count[i] = 0;
    }
    for (int i = 0; i < size; i++)
    {
        count[arr[i] - min]++;
    }
    for (int i = 1; i < range; i++)
    {
        count[i] += count[i - 1];
    }
    for (int i = size - 1; i >= 0; i--)
    {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }
    for (int i = 0; i < size; i++)
    {
        arr[i] = output[i];
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
    count_sort(arr, size);
    display(arr, size);
    return 0;
}
