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

void update(int *tree, int start, int end, int index, int idx, int value) {
    if(start == end) {
        tree[index] = value;
        return;
    }

    int mid = (start + end) / 2;

    if(idx > mid) {
        update(tree, mid + 1, end, 2 * index + 1, idx, value);
    } else {
        update(tree, start, mid, 2 * index, idx, value);
    }

    tree[index] = min(tree[2 * index], tree[2 * index + 1]);
}


void printTree(int tree[], int n) {
    for(int i = 1; i < 4 * n + 1; i++) {
        cout<<tree[i]<<" ";
    }
    cout<<endl;
}




int main() {

  /* 
  modify the input in this way
  5 5
1 5 2 4 3
q 1 5
q 1 3
q 3 5
u 3 6
q 1 5
  
  */ 

  int n ; 
    cin>>n;
    int arr[n+1];
    for(int i = 1; i <= n; i++) {
        cin>>arr[i];
    }
    int tree[4 * n + 1] = {0};

    buildTree(arr, tree, 1, n, 1);
    int q;
    cin>>q;
    while(q--) {
        char c;
        cin>>c;
        if(c == 'q') {
            int l, r;
            cin>>l>>r;
            cout<<query(tree, 1, n, 1, l, r)<<endl;
        } else  {
            int idx, value;
            cin>>idx>>value;
            update(tree, 1, n, 1, idx, value);
        }
    }

    return 0;
}