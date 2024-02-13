#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minPlatforms(vector<int>& arr, vector<int>& dep) {
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int platforms = 0;
    int maxPlatforms = 0;
    int arrPtr = 0;
    int depPtr = 0;

    while (arrPtr < arr.size() && depPtr < dep.size()) {
        if (arr[arrPtr] < dep[depPtr]) {
            platforms++;
            maxPlatforms = max(maxPlatforms, platforms);
            arrPtr++;
        } else {
            platforms--;
            depPtr++;
        }
    }

    return maxPlatforms;
}

int main() {
    int n;
    cin >> n; // Number of trains

    vector<int> arr(n);
    vector<int> dep(n);

    // Input arrival times
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Input departure times
    for (int i = 0; i < n; i++) {
        cin >> dep[i];
    }

    int minPlatformsReq = minPlatforms(arr, dep);

    cout << "Minimum number of platforms required: " << minPlatformsReq << endl;

    return 0;
}
