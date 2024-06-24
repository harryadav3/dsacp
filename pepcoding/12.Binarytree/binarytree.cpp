#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node * left;
    Node * right;

    Node(int data){
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

void printTree(Node * root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    printTree(root->left);
    printTree(root->right);
}

int main() {

    
    Node * root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->right = new Node(40);
    root->right->left = new Node(50);
    
    printTree(root);

    return 0;
}