// the dutch flag algorithm is used to solve problems like (sort 0 1 2) and (sort colours[leetcode])
// the algortihm uses three pointers low, mid and high
/*
algorithm:
1) all the elements before the low pointer are low values
2) all the elements after the low pointer and before the mid pointer are mid values
3) all the elements after the mid pointer and before the high pointer are unknown values
4) all the elements after the high pointer are high values
initialising:
low = 0
mid = 0
high = size - 1
*/
// to solve the questions the brute force approach would be to use any sorting algorithm which would have O(nlogn) time complexity and O(1) space complexity
// the solution can be further optimised by using the counting sort algorithm in which first count the 0s 1s and 2s and then put them in order in the array so the time complexity would be O(n + n) = O(2n) = O(n) and the space complexity would be O(n)
// further this can be optimised using the dutch flag algorithm
/*
using the dutch flag algorithm each element is traversed one by one
the mid pointer will be used to traverse the elements and the low and high pointer will be used only to swap the low and high value in their right place
there will be three cases when traversing the elements
1) the element encountered is 0 : swap the mid element with the element at the low and increment low and mid
swap (arr[mid++], arr[low++])
2) the element encountered is 1: since 1 is a mid value it does not need to be sorted as it will automatically get sorted on sorting the higher and lower values so the mid pointer will simply be incremented on encountering a mid value
mid++
3) the element encountered i 2: swap the mid element with the element at the high and decrement high. by decrementing high the rule that all the elements to the right of high are high elements stays true. mid will not be incremented here since the element which is swapped with high is an unknown value and must stay between the mid and high pointer inclusive of the mid and high pointer
swap(arr[mid], arr[high--])
*/
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
void sort012(int *arr, int size)
{
    int low = 0;
    int mid = 0;
    int high = size - 1;
    while (mid <= high)
    {
        switch (arr[mid])
        {
        case 0: // swap element and low and mid pointer and increment low and mid pointer
            swap(arr[mid++], arr[low++]);
            break;
        case 1: // mid value hence no swapping increment mid pointer
            mid++;
            break;
        case 2: // swap value at high and mid pointer and decrement high pointer
            swap(arr[mid], arr[high--]);
            break;
        }
    }
    display(arr, size);
}
int main()
{
    int size = 0;
    cout << "enter the size of the array: ";
    cin >> size;
    cout << "enter the elements in the array (0, 1 or 2) : ";
    int *arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    sort012(arr, size);
    return 0;
}