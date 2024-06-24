#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;
        Node(int data) {
            this->data = data;
            left = right = NULL;
        }
};

Node* buildTree(vector<int>tree) {
    stack<Node*> s;
    Node *root = new Node(tree[0]);
    s.push(root);
    for(int i = 1; i<tree.size(); i++) {
        if(tree[i] == -1) {
            s.pop();
        } else {
            Node *temp = new Node(tree[i]);
            if(s.top()->left == NULL) {
                s.top()->left = temp;
            } else {
                s.top()->right = temp;
            }
            s.push(temp);
        }
    }
    return root;
}

Node *masabuildTree() {
    int d ;
    cin>>d;

    if(d == -1) {
        return NULL;
    }

    Node *root = new Node(d);
    root->left = masabuildTree();
    root->right = masabuildTree();

    return root;
}

void printTree(Node *root) {
    if(root == NULL) {
        return ;
    }

    cout<<root->data<<" ";
    printTree(root->left);
    printTree(root->right);
}

void rootToleatpaths(Node *root, vector<int> &path) {
    if(root == NULL) {
        return;
    }
    if(root->left == NULL && root->right == NULL) {
        for(int i = 0; i<path.size(); i++) {
            cout<<path[i]<<" ";
        }
        cout<<endl;
    }
    path.push_back(root->data);
    rootToleatpaths(root->left, path);
    rootToleatpaths(root->right, path);
    path.pop_back();
}
bool search ( Node *root, int key) {
    if(root == NULL ) {
        return false;
    }

    if(root->data == key || search(root->left, key)  || search(root->right , key)){
        return true;
    }
    return false;
}

void levelOrderTraversal(Node *root) {
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node *temp = q.front();
        q.pop();

        if(temp == NULL) {
            q.pop();
            cout<<endl;
            if(!q.empty()) {
                q.push(NULL);
            }
        } else {
        cout<<temp->data<<" ";
        if(temp->left) {
            q.push(temp->left);
        }
        if(temp->right) {
            q.push(temp->right);
        }


        }
        }
}

int main() {

     vector<int> tree = { 1,2,4, -1,-1 ,5, 7, -1, -1, -1 , 3 ,-1,  6, -1, -1};
        Node *root = buildTree(tree);
        // Node *root = masabuildTree();
        printTree(root);
        cout<<search(root, 5);
        cout<<endl;
        levelOrderTraversal(root);

    return 0;
}