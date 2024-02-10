//solve the GSS1 question on the spoj
// using segment tress as arrays
#include <bits/stdc++.h>
using namespace std;




void buildTree(int *arr, int *tree, int start, int end, int index) {
    if(start == end) {
        tree[index] = arr[start];
        return;
    }

    int mid = (start + end) / 2;

    buildTree(arr, tree, start, mid, 2 * index);
    buildTree(arr, tree, mid + 1, end, 2 * index + 1);

    tree[index] = max(tree[2 * index] , tree[2 * index + 1]);
}


int query(int *tree, int start, int end, int index, int left, int right) {
   
    if(start > right || end < left) {
        return INT_MIN;
    }

    if(start >= left && end <= right) {
        return tree[index];
    }

    int mid = (start + end) / 2;
    int ans1 = query(tree, start, mid, 2 * index, left, right);
    int ans2 = query(tree, mid + 1, end, 2 * index + 1, left, right);

    return max(ans1, ans2);
}


int main() {

    int n;
    cin>>n;

    int arr[n];
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
    }

    int tree[4 * n + 1] = {0};

    buildTree(arr, tree, 0, n - 1, 1);

    int q;
    cin>>q;

    while(q--) {
        int l, r;
        cin>>l>>r;
        cout<<query(tree, 0, n - 1, 1, l - 1, r - 1)<<endl;
    }

    return 0;
}

