// create a binary tree with struct node as Node , data left and right pointer

// first line of input will be number of nodes
// second line of input will be the root node
// third line of remaining input will be the nodes of the tree


// Structure for binary tree node 
#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};



// function to build the tree 

TreeNode* buildTree(int n, int rootVal, vector<int> nodes) {
    TreeNode* root = new TreeNode(rootVal);
    queue<TreeNode*> q;
    q.push(root);
    int i = 0;
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (i < n) {
            if (nodes[i] != -1) {
                node->left = new TreeNode(nodes[i]);
                q.push(node->left);
            }
            i++;
            if (i < n) {
                if (nodes[i] != -1) {
                    node->right = new TreeNode(nodes[i]);
                    q.push(node->right);
                }
                i++;
            }
        }
    }
    return root;
}
// print the tree
void printTree(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    int level = 0; // Initialize the level number
    int maxLevel = 0; // Initialize the level number with maximum weight
    double maxWeight = 0.0; // Initialize the maximum weight
    while (!q.empty()) {
        int size = q.size();
        int levelSum = 0; // Initialize the sum of the current level
        int nodeCount = 0; // Initialize the number of nodes on the current level
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();
            levelSum += node->val; // Add the node value to the level sum
            nodeCount++; // Increment the node count
            if (node->left) {
                q.push(node->left);
                cout << "Edge: " << node->val << " -> " << node->left->val << endl;
            }
            if (node->right) {
                q.push(node->right);
                cout << "Edge: " << node->val << " -> " << node->right->val << endl;
            }
        }
        double weight = static_cast<double>(levelSum) / nodeCount; // Calculate the weight of the current level
        if (weight > maxWeight) {
            maxWeight = weight;
            maxLevel = level;
        }
        level++; // Increment the level number
    }
    cout << "Level with maximum weight: " << maxLevel + 1 << ", Weight: " << maxWeight << endl;
}

int main() {
    int n;
    cin >> n;
    int rootVal;
    cin >> rootVal;
    vector<int> nodes(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> nodes[i];
    }
    TreeNode* root = buildTree(n - 1, rootVal, nodes);
    printTree(root);
    return 0;
}


/*

6 
10
8 20 6 9 17

*/