// this is the stl tutorial by love babbar
/*
// basic array and stl array
#include <iostream>
#include <array>
using namespace std;
int main()
{
    // basic array
    int arr1[2] = {0, 1};
    // stl array
    array<int, 2> arr2 = {0, 1};
    // printing basic array element
    cout << arr1[1] << endl;
    // printing stl array element
    cout << arr2[1] << endl;
    // finding the size of the array
    int size = arr2.size();
    cout << "the size of the stl array is: " << size << endl;
    // direct access of an element at an index position use 'at' function
    cout << "the element in the stl array at index 1 is :" << arr2.at(1) << endl;
    // checking if an array is empty or not[with a full array] (will return boolean value)
    if (arr2.empty())
        cout << "the arr2 array is empty." << endl;
    else
        cout << "the arr2 array is not empty" << endl;
    // checking if an array is empty or not[with an empty array]
    array<int, 0> temparr;
    if (temparr.empty())
        cout << "the tempp array is an empty array. " << endl;
    else
        cout << "the temp array is not an empty array." << endl;
    // to access the first element of the array
    cout << "the first element in the array is: " << arr2.front() << endl;
    // to access the last element of the array
    cout << "the last element in the array is: " << arr2.back() << endl;
    return 0;
}
// time complexity for all is O(1)
*/
/*vectors in stl
// vector is a dynamic array : if the size of the vector array is 3 and more than those number of elements are put in the array a vector double the size of the made vector is made and all the elements of the old vector are shifted to the new vector. it knows how to increase or decrease its size and hence its called dynamic array. 'Shrink to fit' operation can be used to decrease the size of the memory. Random accessing of elements in a vector array is possible.
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v;
    // the vector on initialisation will have capacity 0
    cout << "the capacity of the vector to check the amount of memory allocated to the vector is: " << v.capacity() << endl;
    // to insert (push) an element into a vector use the 'push_back' function
    v.push_back(1); // here the vector will get capacity 1
    cout << "the capacity of the vector to check the amount of memory allocated to the vector is: " << v.capacity() << endl;
    v.push_back(2); // here the vector will get capacity 2
    cout << "the capacity of the vector to check the amount of memory allocated to the vector is: " << v.capacity() << endl;
    v.push_back(3); // here the vector will fall short of capacity and hence double the capacity of the vector to 4
    cout << "the capacity of the vector to check the amount of memory allocated to the vector is: " << v.capacity() << endl;
    // to see the size of the vector (how many elements are present in the vector)
    cout << "the size of the vector is: " << v.size() << endl;
    // random accessing of elements can be done using the 'at' function
    // cout << the element at the nth index position is vector.at(n)
    cout << "the element at the 2nd index position is: " << v.at(2) << endl;
    // to see the first and last element in the vector use the 'front' and 'back' function
    cout << "the first element in the vector is: " << v.front() << endl;
    cout << "the last element in the vector is: " << v.back() << endl;
    // to print all the elements in the vector
    cout << "before pop" << endl;
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    // to remove an element in the array use the 'pop_back' function. Adding and deleting elements in the vector work on the LIFO - Last In First Out principle. Pop back will delete the last element in the vector
    v.pop_back();
    cout << "after pop" << endl;
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    // to clear the vector use the 'clear' function. By using this function only the elements in the array get deleted i.e the size of the vector becomes 0 but the capacity of the vector remains the same (here 4)
    cout << "size: " << v.size() << endl;
    cout << "capacity : " << v.capacity() << endl;
    v.clear();
    cout << "size: " << v.size() << endl;
    cout << "capacity : " << v.capacity() << endl;
    // adding back elements to the vector
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    // An iterator is an object (like a pointer) that points to an element inside the container. We can use iterators to move through the contents of the container. They can be visualized as something similar to a pointer pointing to some location and we can access the content at that particular location using them.
    // to get the iterator to the first element of the vector container use the 'begin' function.
    // to get the iterator of the end element of the vector container use the 'end' function.
    // using begin() and end() to print the elements in the vector
    cout << "using begin() and end() function to print the elements in the vector: ";
    for (auto iterator = v.begin(); iterator != v.end(); iterator++)
    {
        cout << " " << *iterator; // using indirection/dereferencing operator to get the value of the iterator (same as using dereference operator to dereference a pointer)
    }
    cout << endl;
    v.clear();
    // initializing the vector (when vector to be made is of known size)
    // vector <datatype> vector_name (size, value_to_be_initialized_with);
    vector<int> tempvector(3, 2);
    cout << "the values in the tempvector vector is: ";
    for (int i : tempvector)
    {
        cout << i << " ";
    }
    // to create a vector with the same elements as another vector
    // copying the elements of tempvector into copied_vector
    vector <int> copied_vector(tempvector);
    return 0;
}
*/
/*deque in stl
// deque can be called DQ or double ended queue
#include <iostream>
#include <deque>
using std::cout;
using std::deque;
using std ::endl;
int main()
{
    // to create a deque
    deque<int> d; // deque of type int created
    // to insert elements in the deque
    d.push_back(1);  // inserting an element at the back of the queue
    d.push_front(2); // inserrting an element at the from of the queue
    // printing the elements in a queue
    // here 2 is inserted at the front and 1 is inserted at the end so 2 1 must get printed
    cout << "the numbers in the deque are -> ";
    for (int i : d)
    {
        cout << i << " ";
    }
    cout << endl;
    // to delete elements in the deque
    d.pop_back(); // to delete an element from the back of the deque
    // printing the elements
    for (int i : d)
    {
        cout << i << " ";
    }
    cout << endl;
    d.pop_front(); // to delete an element from the start of the deque
    // printing the element (here nothing will get printed as the deque is empty)
    for (int i : d)
    {
        cout << i << " ";
    }
    cout << endl;
    d.push_front(1);
    d.push_front(2);
    d.push_front(3);
    // to access an element in a deque at a particular index position ust the at() function
    cout << "the number at the 2nd index position in the deque -> " << d.at(2) << endl;
    // to access the first and last element in a deque use the front() and back() functions
    cout << "the number at the start of the deque is -> " << d.front() << endl;
    cout << "the number at the end of the deque is -> " << d.back() << endl;
    // to check if a deque is empty or not use the empty() function
    cout << d.empty(); // it will print 1 if the deque is empty or 0 if it is not empty
    cout << endl;
    // to get the iterator of the starting element of the deque use the begin() function
    // to get the iterator of the end element of the deque use the end() function
    auto begin_iterator = d.begin();
    auto end_iterator = d.end();
    cout << "printing the first element using iterator -> " << *begin_iterator << endl;
    cout << "printing the last element using iterator -> " << *end_iterator << endl;
    // to print the size of the deque
    cout << "the size of the deque is -> " <<  d.size() << endl;
    // to erase the the elements in the deque (deleting all the elements in the deque)
    d.erase(d.begin(), d.begin()+1); // two arguments in this function giving the start and end point for the elements to be deleted. All the elements from the start to the end point given in the arguments will be deleted.
    cout << "the size of the deque after emptying -> " << d.size() << endl;
    // the size of the deque becomes 0 after erasing but the max size (the memory allocated to the deque) remains
    return 0;
}
*/
/*list in stl
// the implementation of list occurs due to doubl-linked lists. lists stl is made using the double-linked lists. Double-linked lists have two pointers one at the front and one at the back.
//  Direct accessing of elements using index or at() function is not possible in lists.
#include <iostream>
#include <list>
using namespace std;
int main()
{
    // creating a list
    list<int> l;
    // inserting an element in the list
    l.push_back(1);  // through the end of the list
    l.push_front(2); // through the start of the list
    l.push_front(3);
    l.push_front(4);
    // to print the elements in the list
    cout << "the elements in the list are: ";
    for (int i : l) // read as (int i belongs to l)
    {
        cout << i << " ";
    }
    cout << endl;
    // to check if the list is empty use the empty() function
    cout << l.empty() << endl; // will print 0 if the list is not empty and 1 if it is empty
    // to get the iterator of the starting element of the list use the begin function
    //  to get the iterator of the ending element of the list use the end function
    auto list_begin_iterator = l.begin();
    auto list_end_iterator = l.end();
    cout << "the first element in the list printed using the begin iterator is: " << *list_begin_iterator << endl;
    cout << "the end element in the list printed using the end iterator is: " << *list_end_iterator << endl;
    // using the erase function to delete elements in a list
    cout << "before erasing the elements in the list are: ";
    for (int i : l)
    {   
        cout << i << " ";
    }
    cout << endl;
    l.erase(l.begin());
    cout << "after erasing the elements in the list are: ";
    for (int i : l)
    {
        cout << i << " ";
    }
    cout << endl;
    // to delete multiple elements
    cout << "to delete multiple elements" << endl;
    // adding back deleted elements
    l.push_front(4);
    cout << "before erasing : ";
    for (int i : l)
    {
        cout << i << " ";
    }
    cout << endl;
    // lists do not have random access iterators so to delete multiple elements use the stl :: advance() function
    list<int>::iterator range_begin = l.begin(); // setting an iterator at the start of the list to set the beginning point to erase elements
    list<int>::iterator range_end = l.begin();   // setting an iterator at the start of the list to set the end point to erase elements
    std::advance(range_begin, 2);                // using the advance() function to increment the range iterator
    std::advance(range_end, 4);                  // the second argument is the index position
    l.erase(range_begin, range_end);             // erasing the elements in the range
    cout << "after erasing: ";
    for (int i : l)
    {
        cout << i << " ";
    }
    cout << endl;
    // to delete single elements from the list the pop_front() and pop_back() functions can be used
    l.pop_back();
    l.pop_front();
    // to check the size of the list the size() function can be used
    cout << "the size of the list is: " << l.size() << endl;
    l.push_front(4);
    l.push_front(3);
    l.push_front(2);
    l.push_front(1);
    // to copy the list into another list
    list<int> new_list(l);
    cout << "the elements in the new list are: ";
    for (int i : new_list)
    {
        cout << i << " ";
    }
    cout << endl;
    // to initialize all the elements in the list with a certain value
    list<int> new_list_2(2, 10); // this new_list_2 will have 2 elements and both will be 10
    cout << "the elements in the initialized list are: ";
    for (int i : new_list_2)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

*/
/*stacks in stl
// stacks have a LIFO- Last In First Out working
#include <iostream>
#include <stack>
using namespace std;
int main()
{
    // creating a stack
    stack<string> s;
    // to add items to the stack use the push() function
    s.push("dive");
    s.push("the");
    s.push("loop");
    // to print the topmost element in the stack use the top() function
    cout << "the topmost element in the stack is: " << s.top() << endl;
    // to remove an element from the stack use the pop() function
    s.pop(); //the element that was pushed last into the stack will get popped
    // to check the size of the stack use the size() function
    cout << "the size of the stack is: " << s.size() << endl;
    //to check if the stack is empty or not ue the empty() function
    cout << s.empty() << endl; //will print 1 if the stack is empty and 0 if it is not empty

    return 0;
}
*/
/*queues in stl
// queues have a FIFO- First In First Out working
#include <iostream>
#include <queue>
using namespace std;
int main()
{
    // creating a queue
    queue<string> q;
    // to add elements to the queue use the push() function
    q.push("dive");
    q.push("the");
    q.push("loop");
    // to check the first and last elements in the queue use the front() and back() functions
    cout << "the first element in the queue is: " << q.front() << endl;
    cout << "the last element in the queue is: " << q.back() << endl;
    // to remove elements from the queue use the pop() function
    q.pop(); // the element that was pushed first into the track will get popped
    // to check the size of the queue use the size() function
    cout << "the size of the queue is: " << q.size() << endl;
    // to check if the queue is empty or not ue the empty() function
    cout << q.empty() << endl; // will print 1 if the queue is empty and 0 if it is not empty

    return 0;
}
*/

/*
!!IMP!!:
STACK ALLOCATION: The allocation happens on contiguous blocks of memory. We call it a stack memory allocation because the allocation happens in the function call stack. The size of memory to be allocated is known to the compiler and whenever a function is called, its variables get memory allocated on the stack. And whenever the function call is over, the memory for the variables is de-allocated.
HEAP ALLOCATION: The memory is allocated during the execution of instructions written by programmers. Note that the name heap has nothing to do with the heap data structure. It is called heap because it is a pile of memory space available to programmers to allocated and de-allocate. Every time when we made an object it always creates in Heap-space and the referencing information to these objects are always stored in Stack-memory.
*/

/*
A Heap is a special Tree-based data structure in which the tree is a complete binary tree. Generally, Heaps can be of two types:
Max-Heap: In a Max-Heap the key present at the root node must be greatest among the keys present at all of it’s children. The same property must be recursively true for all sub-trees in that Binary Tree.
Min-Heap: In a Min-Heap the key present at the root node must be minimum among the keys present at all of it’s children. The same property must be recursively true for all sub-trees in that Binary Tree.
*/

/*Priority Queue
// priority queue is a queue whos first element is always either the greatest (max_heap) or the smallest(min_heap). The default priority queue is max_heap. Heap is a tree based data structure in which the tree is a binary tree.
// What is the difference between minheap/maxheap and priority queue? Priority queue is the application of min heap maz heap.
#include <iostream>
#include <priority_queue>
using namespace std;
int main()
{
    // creating a priority queue
    // max-heap
    priority_queue<int> maxi;
    // min-heap
    priority_queue<int, vector<int>, greater<int>> mini;
    // pushing data into the max heap
    maxi.push(1);
    maxi.push(2);
    maxi.push(3);
    maxi.push(0);
    // printing the data in the max heap priority queue
    int n = maxi.size(); // size function to get the size of the heap
    cout << "the elements in the queue are: ";
    for (int i = 0; i < n; i++) // cant use i < maxi.size() as the size keeps changing after popping
    {
        cout << maxi.top() << " "; // prints the topmost element in the queue which is the largest element in case of max_heap priority queue
        maxi.pop();
    }
    cout << endl;
    // pushing the data in the min heap priority queue
    mini.push(6);
    mini.push(4);
    mini.push(9);
    mini.push(1);
    // printing the data in the min heap priority queue
    int m = mini.size();
    cout << "the elements in the queue are: ";
    for (int i = 0; i < m; i++)
    {
        cout << mini.top() << " "; // top() function returns the smallest value in the priority queue in case of min_heap priority queue
        mini.pop();                // pop() function to delete the element in the priority queue
    }
    cout << endl;
    // to check if the queue is empty use the empty() function
    cout << mini.empty(); //will print 0 if the queue is full and 1 if it is empty
    cout << maxi.empty(); //will print 0 if the queue is full and 1 if it is empty
    return 0;
}
*/
/*Set in stl
// sets have only unique elements. if an element is pushed multiple times into the set it will still have only one osccurence in the set as set stores each element only once. it is implemented using BST( Binary search tree). if an element is pushed to the set it cannot be modified. elements are returned in sorted manner. unordered sets are faster than sets but will have random order of extraction of elements.
#include <iostream>
#include <set>
using namespace std;
int main()
{
    // creating a set
    set<int> s;
    // inserting elements in the set
    // the complexity of the insert() function is O(logn)
    s.insert(5);
    s.insert(5);
    s.insert(5);
    s.insert(6);
    s.insert(6);
    s.insert(0);
    s.insert(0);
    s.insert(1);
    // printing the elements in the set
    cout << "the elements in the set are: ";
    for (auto i : s)
    {
        cout << i << " ";
        // the elements will be printed in sorted order
    }
    cout << endl;
    // to check the size of the set
    cout << "the size of the set is :" << s.size() << endl; // set does not store more than one occurence of any element
    // finding an element. an iterator is needed to use the find function. if the element is present in the set the function returns a pointer pointing to the element in the set. if the element being searched for is not present in the set an iterator pointing to the end of the set is returned.
    set<int>::iterator to_find = s.find(5);
    if (to_find != s.end())
    {
        cout << "the element " << *to_find << " is present in the set" << endl;
    }
    else
    {
        cout << "the element is not present in the set" << endl;
    }
    // to delete elements in the set use the erase() function. an iterator is needed to use the erase() function.
    set<int>::iterator to_erase = s.begin();
    to_erase++;
    s.erase(to_erase);
    cout << "the elements after deleting the second element are: ";
    for (auto i : s)
    {
        cout << i << " ";
    }
    cout << endl;
    // to check if an element is present in the set use the count function
    cout << s.count(5) << endl; //returns 0 if the element is not present in the set and 1 if the element is present.
    // to check if the set is empty or not use the empty() function
    cout << s.empty() << endl; // returns 0 if the set is not empty and 1 if it is empt.
    // the complexity of insert(), find(), erase(), count() is O(log n).
    // the complexity of begin(), end(), size(), empty() is O(1).
    return 0;
}
*/
/*Map in stl
// map is a data structure in which the data is stored in a key-value form. all keys are unique and one key can point to only one value. 2 keys can point to a single value.
#include <iostream>
#include <map>
using namespace std;
int main()
{
    // creating a map
    map<int, string> m;
    // adding data to the map
    m[1] = "honey";
    m[2] = "is";
    m[6] = "food";
    m[5] = "very";
    // another way to insert data in the map is to use the insert() function
    m.insert({4, "good"});
    // printing the data in the map
    // The ranged-for returns all items as a std::pair<int, string>.std::pair has two public variables; "first", and "second"
    for (auto i : m)
    {
        // printing occurs in the sorted order
        cout << i.first << endl; // first will print the key part
    }
    cout << "--------" << endl;
    for (auto i : m)
    {
        cout << i.second << endl; // second will print the value part
    }
    // to check if an element is present in the map use the count() function
    cout << m.count(2) << endl; // returns 0 if the element is not present in the set and 1 if the element is present.
    cout << "--------" << endl;
    // to delete an element in the map use the erase() function
    m.erase(5);
    for (auto i : m)
    {
        cout << i.first << " " << i.second << endl;
    }
    // in case of map the complexity for insert(), find(), count() is O(logn)
    // to find an element in the map. iterator is needed to use the find() function. Searches the container for an element with a key equivalent to k and returns an iterator to it if found, otherwise it returns an iterator to map::end.
    auto it = m.find(4);
    if( it != m.end())
    {
        cout << "the element " << (*it).first << " is present" << endl;
    }
    else
    {
        cout << "the element is not present in the map" << endl;
    }
    // for (auto i = it; i != m.end(); i++)
    // {
    //     cout << (*it).first << endl;
    // }
    return 0;
}
*/
/*stl algorithms
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(5);
    v.push_back(7);
    v.push_back(9);
    // binary search
    cout << binary_search(v.begin(), v.end(), 5) << endl; // prints 1 if the element is found else prints 0.
    // lower bound
    // Syntax 1: ForwardIterator lower_bound (ForwardIterator first, ForwardIterator last, const T& val); Syntax 2: ForwardIterator lower_bound (ForwardIterator first, ForwardIterator last, const T& val, Compare comp);  This means that the function returns an iterator pointing to the next smallest number just greater than or equal to that number. If there are multiple values that are equal to val, lower_bound() returns the iterator of the first such value. The elements in the range shall already be sorted or at least partitioned with respect to val.
    // doubt :- why do i have to subtracto it v.begin() ??
    // answer:- you dont thats personal choice and doesnt have anything to do with the lower bound. lower bound will return an iterator pointing to the first element >= the element to compare with (say x) (x = 5 in the case below). which is the element if it is present in the vector. and the begin function will return a vector pointing to the first element in the vector. so if you subtract vector_name.begin() from the iterator pointing to x you get the offset of that from the beginning of the vector so the index of the element
    // in the lower case lower_bound(v.begin(),v.end(), 5) will return and iterator will be pointing to 5 in the vector so on subtracting the address of the first element from it will give the index of 5 in the vector (here 2)
    cout << "lower bound " << lower_bound(v.begin(), v.end(), 5) - v.begin() << endl;
    // upper bound
    cout << "upper bound " << upper_bound(v.begin(), v.end(), 5) - v.begin() << endl;
    // max and min value
    int a = 100;
    int b = 20;
    int c = 20;
    cout << "the maximum value among the two values are: " << max(a, b) << endl;
    cout << "the minimum value among the two values are: " << min(a, b) << endl;
    // swapping two values
    cout << "value of a before swapping: " << a << endl;
    cout << "value of b before swapping: " << b << endl;
    swap(a, b);
    cout << "value of a after swapping: " << a << endl;
    cout << "value of b after swapping: " << b << endl;
    // reversing a string
    string s = "abcd";
    reverse(s.begin(), s.end());
    cout << "the reversed string is: " << s << endl;
    // rotating a vector
    cout << "before rotating : ";
    for (int i : v)
    {
        cout << i << " ";
    }
    rotate(v.begin(), v.begin() + 2, v.end());
    cout << endl <<  "after rotating : ";
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    // sorting
    // this sorting algorithm is based on introsort which is a combination of three sorting algorithms namely quick sort, heap sort and insertion sort.
    return 0;
}
*/
