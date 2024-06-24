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

    tree[index] = min(tree[2 * index] , tree[2 * index + 1]);
}

int query(int *tree, int start, int end, int index, int left, int right) {
   
    if(start > right || end < left) {
        return INT_MAX;
    }

    if(start >= left && end <= right) {
        return tree[index];
    }

    int mid = (start + end) / 2;
    int ans1 = query(tree, start, mid, 2 * index, left, right);
    int ans2 = query(tree, mid + 1, end, 2 * index + 1, left, right);

    return min(ans1, ans2);
}


void updaterange(int *tree, int start, int end, int index, int updatestart, int updateend, int value) {
    if(start > updateend || end < updatestart) {
        return;
    }

    if(start == end) {
        tree[index] += value;
        return;
    }

    int mid = (start + end) / 2;

    updaterange(tree, start, mid, 2 * index, updatestart, updateend, value);
    updaterange(tree, mid + 1, end, 2 * index + 1, updatestart, updateend, value);

    tree[index] = min(tree[2 * index], tree[2 * index + 1]);
}

//print tree array
void printTree(int tree[], int n) {
    for(int i = 1; i < 4 * n + 1; i++) {
        cout<<tree[i]<<" ";
    }
    cout<<endl;
}



int main() {

   
    int n = 7;

    int arr[]  = {3,5,1,6,2,7,4};

   int tree[4 * n + 1] = {0};

    buildTree(arr, tree, 0, n - 1, 1);

    cout<<query(tree, 0, n - 1, 1, 4, 5)<<endl;
    printTree(tree, n);

    cout<<"update range"<<endl;
    updaterange(tree, 0, n - 1, 1, 2, 5, 10);
    printTree(tree, n);

    return 0;
}