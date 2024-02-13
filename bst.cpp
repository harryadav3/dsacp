#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int val;
    Node* l;
    Node* r;
    Node(int x) : val(x), l(nullptr), r(nullptr) {}
};

void inorder(Node* root, vector<int>& v) {
    if (root == nullptr) return;
    inorder(root->l, v);
    v.push_back(root->val);
    inorder(root->r, v);
}

Node* buildBST(vector<int>& v, int start, int end) {
    if (start > end) return nullptr;
    int mid = start + (end - start) / 2;
    Node* root = new Node(v[mid]);
    root->l = buildBST(v, start, mid - 1);
    root->r = buildBST(v, mid + 1, end);
    return root;
}

void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->val << " ";
    preorder(root->l);
    preorder(root->r);
}

int main() {
    int N;
    cin >> N;

    vector<int> v(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
    }

    vector<int> sorted;
    inorder(buildBST(v, 0, N - 1), sorted);

    Node* balanced = buildBST(sorted, 0, N - 1);

    cout << "Preorder of balanced BST: ";
    preorder(balanced);
    cout << endl;

    return 0;
}
