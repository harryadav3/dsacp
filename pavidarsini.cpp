#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int countMatchingRanges(int n, vector<int>& nums) {
    unordered_map<long long, int> freq;
    long long product = 1;
    int count = 0;

    for (int i = 0; i < n; ++i) {
        product *= nums[i];
        freq[product]++;
        if (product == 1) {
            count += i; // Include all previous numbers
        } else {
            count += freq[product] - 1; // Exclude the current number
        }
    }

    return count;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int ways = countMatchingRanges(n, nums);
    cout << ways << endl;

    return 0;
}
