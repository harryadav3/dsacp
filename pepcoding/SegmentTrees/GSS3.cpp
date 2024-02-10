//solve GSS3 problem question of spoj

#include <bits/stdc++.h>
using namespace std;

struct node {
    int sum;
    int maxsum;
    int prefixsum;
    int suffixsum;
};


void buildTree(int *arr, node *tree, int start, int end, int index) {
    if(start == end) {
        tree[index].sum = arr[start];
        tree[index].maxsum = arr[start];
        tree[index].prefixsum = arr[start];
        tree[index].suffixsum = arr[start];
        return;
    }

    int mid = (start + end) / 2;

    buildTree(arr, tree, start, mid, 2 * index);
    buildTree(arr, tree, mid + 1, end, 2 * index + 1);

    tree[index].sum = tree[2 * index].sum + tree[2 * index + 1].sum;
    tree[index].prefixsum = max(tree[2 * index].prefixsum, tree[2 * index].sum + tree[2 * index + 1].prefixsum);
    tree[index].suffixsum = max(tree[2 * index + 1].suffixsum, tree[2 * index + 1].sum + tree[2 * index].suffixsum);
    tree[index].maxsum = max(tree[index].prefixsum, max(tree[index].suffixsum, max(tree[2 * index].maxsum, max(tree[2 * index + 1].maxsum, tree[2 * index].suffixsum + tree[2 * index + 1].prefixsum))));
}


node query(node *tree, int start, int end, int index, int left, int right) {
    node result;
    result.sum = result.maxsum = result.prefixsum = result.suffixsum = INT_MIN;

    if(start > right || end < left) {
        return result;
    }

    if(start >= left && end <= right) {
        return tree[index];
    }

    int mid = (start + end) / 2;
    if(left > mid) {
        return query(tree, mid + 1, end, 2 * index + 1, left, right);
    }
    if(right <= mid) {
        return query(tree, start, mid, 2 * index, left, right);
    }

    node leftans = query(tree, start, mid, 2 * index, left, right);
    node rightans = query(tree, mid + 1, end, 2 * index + 1, left, right);

    result.sum = leftans.sum + rightans.sum;
    result.prefixsum = max(leftans.prefixsum, leftans.sum + rightans.prefixsum);
    result.suffixsum = max(rightans.suffixsum, rightans.sum + leftans.suffixsum);
    result.maxsum = max(result.prefixsum, max(result.suffixsum, max(leftans.maxsum, max(rightans.maxsum, leftans.suffixsum + rightans.prefixsum))));

    return result;
}



int main() {

    int n;
    cin>>n;

    int arr[n];
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
    }

    node tree[4 * n + 1];

    buildTree(arr, tree, 0, n - 1, 1);

    int q;
    cin>>q;

    while(q--) {
        int l, r;
        cin>>l>>r;
        cout<<query(tree, 0, n - 1, 1, l - 1, r - 1).maxsum<<endl;
    }

    return 0;
}