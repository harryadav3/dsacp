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


Node* insert(Node* root, int key) {

    if(root == NULL ){
        return new Node(key);
    }
    if( key < root->data) {
        root->left = insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }

    return root;
    
}

void levelorder (Node* root) {
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

Node* search(Node* root, int key) {
    if(root == NULL) {
        return NULL;
    }
    if(root->data == key) {
        return root;
    }
    if(key < root->data) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

// delete a nde from BST

Node* deleteNode(Node* root, int key) {
    if(root == NULL) {
        return NULL;
    }
    if(key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if(key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if(root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if(root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = root->right;
        while(temp->left != NULL) {
            temp = temp->left;
        }
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

Node* masabremove(Node* root, int key) {
    if( root == NULL ) {
        return NULL;
    }

    if(root->data == key) {
        // case 0 -  no child

        if( root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        // case 1 -> 1 child 

        if(root->left != NULL && root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        if(root->left == NULL && root->right != NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // case 2 -> 2 child
         
         else {
                Node* temp = root->right;
                while(temp->left != NULL) {
                    temp = temp->left;
                }
                root->data = temp->data;
                root->right = masabremove(root->right, temp->data);
                return root;
            
         }
    }
}




Node* createBSt() {
    int data;
    cin>>data;
    Node* root = new Node(data);
    while(data != -1) {
        cin>>data;
        insert(root, data);
    }
    return root;
}



int main() {

     Node* root = createBSt();
    levelorder(root);
    return 0;
}