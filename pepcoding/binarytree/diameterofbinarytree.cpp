#include <bits/stdc++.h>
using namespace std;
class TreeNode {
    public:
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int val) {
            this->val = val;
            left = right = NULL;
        }
};
int height(TreeNode *root) {
    if(root == NULL) return -1;
    int lh = height(root->left);
    int rh = height(root->right);
    return max(lh, rh) + 1;
}

int diameterOfBinaryTree(TreeNode* root) {
    if(root == NULL) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    int ld = diameterOfBinaryTree(root->left);
    int rd = diameterOfBinaryTree(root->right);
    return max(lh + rh + 2, max(ld, rd));
}
class Pair {
    public:
        int height;
        int diameter;
    Pair() {
        height = 0;
        diameter = 0;
    }
};

Pair diameterOptimized(TreeNode *root) {
    Pair p;
    if(root == NULL) return p;
    Pair left = diameterOptimized(root->left);
    Pair right = diameterOptimized(root->right);
    p.height = max(left.height, right.height) + 1;
    p.diameter = max(left.height + right.height + 2, max(left.diameter, right.diameter));
    return p;
}

int main() {

    

    return 0;
}