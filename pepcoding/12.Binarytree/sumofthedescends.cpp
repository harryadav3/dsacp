

#include <bits/stdc++.h>
using namespace std;


class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int data) {
            this->data = data;
            left = right = NULL;
        }
};


void sumOfDescendents(Node *root, int &sum) {
    if(root == NULL) return;
    sumOfDescendents(root->left, sum);
    sumOfDescendents(root->right, sum);
    if(root->left != NULL) {
        sum += root->left->data;
    }
    if(root->right != NULL) {
        sum += root->right->data;
    }
}

void toSumTree(Node *root) {
    if(root == NULL) return;
    toSumTree(root->left);
    toSumTree(root->right);
    if(root->left != NULL) {
        root->data += root->left->data;
    }
    if(root->right != NULL) {
        root->data += root->right->data;
    }
  
}

// insert the sum on th root node and mkae the leaf nodes 0

void toSumTreeOptimized(Node *root) {
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL) {
        root->data = 0;
        return;
    }
    int old = root->data;
    root->data = 0;
    toSumTreeOptimized(root->left);
    toSumTreeOptimized(root->right);
    if(root->left != NULL) {
        root->data += root->left->data;
    }
    if(root->right != NULL) {
        root->data += root->right->data;
    }
    root->data += old;
}
/*
For Input: 
10 -2 6 8 -4 7 5
Your Output: 
8 2 -4 30 7 18 5
Expected Output: 
0 4 0 20 0 12 0
Output Difference
80 2 -4 300 720 180 512 0

answer is not coming correct for this test case

*/

void toSumTreek(Node *root) {
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL) {
        root->data = 0;
        return;
    }
    int old = root->data;
    root->data = 0;
    toSumTreek(root->left);
    toSumTreek(root->right);
    if(root->left != NULL) {
        root->data += root->left->data;
    }
    if(root->right != NULL) {
        root->data += root->right->data;
    }
    root->data += old;
}

/*

Explain
class Solution {
  private:
    void subSum (Node *root, int &sum){
        if(!root)
            return;
        
        subSum(root -> left, sum);
        sum += root -> data;
        subSum(root -> right, sum);
    }
    
    
  public:
    void toSumTree(Node *node)
    {
        if(!node)
            return;
            
        int sum = -(node -> data);
        subSum(node, sum);
        node -> data = sum;
        toSumTree(node -> left);
        toSumTree(node -> right);
    }

    do like this 

};*/

int replace(Node *root) {
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) {
        int temp = root->data;
        root->data = 0;
        return temp;
    }
    int old = root->data;
    root->data = replace(root->left) + replace(root->right);
    return old + root->data;

}

void subsum (Node *root, int &sum){
    if(root == NULL) return;
    subsum(root->left, sum);
    sum += root->data;
    subsum(root->right, sum);
}
void print(Node *root) {
    if(root == NULL) return;
    cout << root->data << " ";
    print(root->left);
    print(root->right);
}

int main() {

    Node *root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(10);
    root->left->left = new Node(20);
    root->left->right = new Node(1);
    root->right->right = new Node(-25);
    root->right->right->left = new Node(3);
    root->right->right->right = new Node(4);
    int sum = 0;
    print(root);
    sumOfDescendents(root, sum);
    cout << sum << endl;
    print(root);

    


    return 0;
}