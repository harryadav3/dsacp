// this technique is used mostly to find pairs in an array that satisfy a certain condition (sorted or unsorted both cases exist)
/*
variants of the two pointer technique :
1) pointers at start and end of the array
2) both pointers at the start of the array
3) pointers one at the start one just after the start (start + 1)
4) slow and fast pointers : both pointers start at the start of the array, the slow pointer increments by one and the fast pointer increments by two and reaches the end of the array in half the time than the slow pointer alternatively it can be saiid that the slow pointer will reach to the mid point (half) of the array when the fast pointer reaches the end of the array
5) more variations may arise depending on the problem
*/
/*
questions related to the two pointer approach
1) two sum : Given a sorted array, check if there exist two numbers whose sum is equal to the given target value.
2) k-subarray sum : Given an array and a number k, find the sum of all the subarrays of size k.
3) Three sum : Given an array A, find all unique triplets in the array whose sum is equal to the given target value.
4) sort 0 1 2 or dutch national flag problem : sort an array containing only 0's 1's and 2's without using any sorting algorithm -> can be solved in O(n) time complexity using djikstra's dutch national flag algorithm
5) trapping rain water : Given an array A where each element denotes a the height of blocks, calculate the total volume of water that can be trapped when it rains.
6) maximum k-subarray sum : Given an array and a number k, find the sum of the subarray that has the maximum sum among all the subarrays of size k.
7) more questions based on strings too can use the two pointer technique. simple questions such as reversing a word can also use the two pointer technique to give the optimal solution
*/
