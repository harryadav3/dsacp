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

class Pair {
    public:
        int inc;
        int exc;
    
    Pair() {
        inc = 0;
        exc = 0;
    }
};
//vector to insert in tree

void insert(vector<int> arr, Node *root) {
   

    for(int i = 1; i < arr.size(); i++) {
        Node *temp = root;
        while(temp != NULL) {
            if(arr[i] < temp->data) {
                if(temp->left == NULL) {
                    temp->left = new Node(arr[i]);
                    break;
                }
                temp = temp->left;
            } else {
                if(temp->right == NULL) {
                    temp->right = new Node(arr[i]);
                    break;
                }
                temp = temp->right;
            }
        }
    }
}

void postorder(Node *root) {


    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
void levelOrder(Node *root) {
    queue<Node *> q;
    q.push(root);
    while(!q.empty()) {
        Node *temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if(temp->left != NULL) q.push(temp->left);
        if(temp->right != NULL) q.push(temp->right);
    }
}

Pair getMaxSum(Node *root){
    if( root == nullptr ) {
        Pair p;
        p.inc = 0;
        p.exc = 0;
        return p;
    }
}

int main() {

    
    vector<int> arr = {10,2,4,8,18,7,11,-3,100,6,-2};
    Node *root = new Node(arr[0]);
    
    insert(arr,root);

    postorder(root);
    cout << endl;
    levelOrder(root);

    return 0;
}