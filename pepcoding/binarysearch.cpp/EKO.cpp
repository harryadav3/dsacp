


#include <bits/stdc++.h>
using namespace std;

int checkHeight(vector<int> &arr, int height) {
    int n = arr.size(); 
    int noOftree = 1;
    long long heightTree = 0;
    for (int i = 0; i < n; i++) {
        if (heightTree + arr[i] <= height) {
            //add height to current student
            heightTree += arr[i];
        }
        else {
            //add height to next student
            noOftree++;
            heightTree = arr[i];
        }
    }
    return noOftree;
}



int main()
{
    vector<int> arr = {20,15,10,7};
    int n = 4;
    int wc = 7;
   //book allocation impossible:
    if (wc > n) return -1;

    int low = *min_element(arr.begin(), arr.end());
    int high = *max_element(arr.begin(), arr.end());
    while (low <= high) {
        int mid = (low + high) / 2;
        int students = checkHeight(arr, mid);
        if (students > wc) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    cout<<low<<endl;
    return 0;
}
