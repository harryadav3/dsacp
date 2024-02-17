#include <iostream>
#include <vector>

using namespace std;

int removeAlternateAndSum(vector<int>& arr) {
    int sum = 0;
    int count = 0;
    vector<int>::iterator it = arr.begin();
    while (arr.size() > 1) {
        if (count % 2 == 0) { // Check if count is even
            sum += *it;
            it = arr.erase(it);
        } else {
            ++it;
        }
        count++;
        if (it == arr.end()) {
            it = arr.begin();
        }
    }
    return sum;
}

int main() {
    // Example usage
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    int removedSum = removeAlternateAndSum(arr);
    
    cout << "Sum of removed alternate elements: " << removedSum << endl;
    
    cout << "Remaining element in the array: " << arr[0] << endl;

    return 0;
}

