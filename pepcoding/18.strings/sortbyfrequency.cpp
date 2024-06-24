#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> // for max
#include <numeric>   // for accumulate
#include <climits>   // for INT_MIN
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to calculate the maximum level weight of a binary tree
double maxLevelWeight(Node* root) {
    if (!root) return 0.0;

    double maxWeight = INT_MIN;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        double levelSum = 0.0;
        for (int i = 0; i < size; i++) {
            Node* node = q.front();
            q.pop();

            levelSum += node->data;

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        double levelWeight = levelSum / size;
        maxWeight = max(maxWeight, levelWeight);
    }

    return maxWeight;
}

int main() {
    int n;
    cin >> n; // Number of elements
    if (n <= 0) {
        cout << "Invalid input!";
        return 0;
    }

    int rootVal;
    cin >> rootVal; // Root element value
    Node* root = new Node(rootVal);

    // Build the binary tree
    for (int i = 1; i < n; i++) {
        int val;
        cin >> val; // Tree elements
        // Assuming the binary tree is being built in level-order
        queue<Node*> levelNodes;
        levelNodes.push(root);

        while (!levelNodes.empty()) {
            Node* current = levelNodes.front();
            levelNodes.pop();

            if (!current->left) {
                current->left = new Node(val);
                break;
            } else {
                levelNodes.push(current->left);
            }

            if (!current->right) {
                current->right = new Node(val);
                break;
            } else {
                levelNodes.push(current->right);
            }
        }
    }

    double maxWeight = maxLevelWeight(root);

    cout << "Maximum level weight: " << maxWeight << endl;

    return 0;
}
