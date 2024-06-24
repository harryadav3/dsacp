#include <bits/stdc++.h>
using namespace std;
// we have to check does the tree height is balanced or not
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
bool isBalanced(Node *root) {
    if(root == NULL) return true;
    int lh = height(root->left);
    int rh = height(root->right);
    if(abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right)) {
        return true;
    }
    return false;
}

class Pair {
    public:
        int height;
        bool isBalanced;
    Pair() {
        height = 0;
        isBalanced = true;
    }
};


Pair isBalancedOptimized(Node *root) {
    Pair p;
    if(root == NULL) return p;
    Pair left = isBalancedOptimized(root->left);
    Pair right = isBalancedOptimized(root->right);
    p.height = max(left.height, right.height) + 1;
    if(abs(left.height - right.height) <= 1 && left.isBalanced && right.isBalanced) {
        p.isBalanced = true;
    } else {
        p.isBalanced = false;
    }
    return p;
}

Pair masabsolution(Node* root) {
    Pair ans;
    if(root == nullptr) return ans;
    Pair left = masabsolution(root->left);
    Pair right = masabsolution(root->right);

        ans.height = max(left.height, right.height) + 1;
        ans.isBalanced = abs(left.height - right.height) <= 1 && left.isBalanced && right.isBalanced;

    return ans;
}
int height(Node *root) {
    if(root == NULL) return 0;
    return max(height(root->left), height(root->right)) + 1;
}
int main() {

    

    return 0;
}