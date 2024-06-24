// create  a binary tree and find the level with maximum weight 
// weight = sum of all nodes at that level / number of nodes at that level
//
// 1. write a fucntion ot build tree 
//  2. find the level with maximum weight and print maximum wight 


#include <bits/stdc++.h>
using namespace std;

// Structure for binary tree node

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to calculate the level order traversal and calculate the weights of each level


pair<int, double> calculateMaxLevelWeight(TreeNode* root) {
    if (!root) return {0, 0.0}; // Return 0 level and weight if the tree is empty

    queue<TreeNode*> q;
    q.push(root);
    double maxWeight = 0.0;
    int maxLevel = 0;
    int level = 0;

    while (!q.empty()) {
        int size = q.size();
        double levelWeight = 0.0;
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();
            levelWeight += node->val; // Add node value to the level weight
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        level++;
        double avgWeight = levelWeight / size; // Calculate average weight of current level
        if (avgWeight > maxWeight) {
            maxWeight = avgWeight;
            maxLevel = level;
        }
    }

    return {maxLevel, maxWeight};
}


int main() {
    int n;
    cin >> n; // Number of elements

    int rootVal;
    cin >> rootVal; // Root element

    TreeNode* root = new TreeNode(rootVal);

    // Construct the binary tree
    for (int i = 1; i < n; i++) {
        int val;
        cin >> val; // Tree elements separated by space
        // BEGIN: abpxx6d04wxr
        // Construct the binary tree by inserting elements
        TreeNode* curr = root;
        while (true) {
            if (val < curr->val) {
                if (curr->left) {
                    curr = curr->left;
                } else {
                    curr->left = new TreeNode(val);
                    break;
                }
            } else {
                if (curr->right) {
                    curr = curr->right;
                } else {
                    curr->right = new TreeNode(val);
                    break;
                }
            }
        }
        // END: abpxx6d04wxr
    }

    pair<int, double> result = calculateMaxLevelWeight(root);
    cout << "Max Level Weight: " << result.second << endl; // Output the maximum weight

    return 0;
}