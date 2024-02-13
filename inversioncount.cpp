#include <iostream>
#include <vector>
using namespace std;

long long merge(vector<int>& arr, int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[low + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    long long inversionCount = 0;
    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
            inversionCount += n1 - i;
        }
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];

    return inversionCount;
}

long long mergeSort(vector<int>& arr, int low, int high) {
    long long inversionCount = 0;
    if (low < high) {
        int mid = low + (high - low) / 2;
        inversionCount += mergeSort(arr, low, mid);
        inversionCount += mergeSort(arr, mid + 1, high);
        inversionCount += merge(arr, low, mid, high);
    }
    return inversionCount;
}

int main() {
    int N;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    long long inversionCount = mergeSort(arr, 0, N - 1);
    cout << inversionCount << endl;

    return 0;
}
