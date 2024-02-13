/*
Problem Statement




Given a BST (Binary Search Tree) that may be unbalanced, convert it into a balanced BST that has the minimum possible height.

Input format :

The first line consists of the number of nodes N.

The second line consists of space-separated integer node values.

Output format :

The output prints pre-order traversal of the balanced binary search tree that has the minimum possible height.




Refer to the sample output for the formatting specifications.

Code constraints :

1 ≤ N ≤ 50

Sample test cases :
Input 1 :
5
5 4 3 2 1
Output 1 :
Preorder Traversal of the balanced BST: 3 1 2 4 5 
Note :
The program will be evaluated only after the “Submit Code” is clicked.
Extra spaces and new line characters in the program output will result in the failure of the test case.

in c++

also kepp variable and funciton name shorter*/


#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int val;
    Node* l;
    Node* r;
    Node(int x) : val(x), l(nullptr), r(nullptr) {}
};


void inorder(Node* root, vector<int>& v) {
    if (root == nullptr) return;
    inorder(root->l, v);
    v.push_back(root->val);
    inorder(root->r, v);
}



Node* buildBST(vector<int>& v, int start, int end) {
    if (start > end) return nullptr;
    int mid = start + (end - start) / 2;
    Node* root = new Node(v[mid]);
    root->l = buildBST(v, start, mid - 1);
    root->r = buildBST(v, mid + 1, end);
    return root;
}



void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->val << " ";
    preorder(root->l);
    preorder(root->r);
}



int main() {
    int N;
    cin >> N;

    vector<int> v(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
    }

    vector<int> sorted;
    inorder(buildBST(v, 0, N - 1), sorted);

    Node* balanced = buildBST(sorted, 0, N - 1);

    cout << "Preorder of balanced BST: ";
    preorder(balanced);
    cout << endl;

    return 0;
}


