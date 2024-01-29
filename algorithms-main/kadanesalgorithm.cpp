// maximum contigious subarray
// find all the contigious subarrays and find the sum of the elements iin that array and the highest sum will be the maximum contigious subarray.
// first approach brute force O(n^3) solution
/*
finding the sum of the elements between the ith and jth pointer using a third iterator k
for (i->n)
{
    for (j = i->n)
    {
        for (k = i->j)
        {
            sum+=array[k]
        }
    }
}
*/

// second approach O(n^2) solution
/*
for (i->n)
{
    sum = 0
    for(j->n)
    {
        sum+=array[j]
    }
}
*/

// optimal solution O(n) using KADANE'S ALGORITHM
/*
4 steps for the algorithm
1: set the sum = 0 and set max_sum = the first element since there will be atleast one element in the array then the maximum sum of the array will be the first element itself
2: sum += arr[i]
3: update the maximum sum hence max_sum = max(max_sum, sum)
4: if the sum < 0 (sum is negative then we do not need to consider that sum and we can set sum to 0)
*/

#include <iostream>
using namespace std;
int kadane(int arr[], int size)
{
    int sum = 0;
    int max_sum = arr[0];
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
        max_sum = max(max_sum, sum);
        if (sum < 0)
        {
            sum = 0;
        }
    }
    return max_sum;
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
    cout << "the maximum subarray sum is: " << kadane(arr, size) << endl;

    return 0;
}