#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    char data;
    bool isTerminal;
    unordered_map<char, Node*> child;
    Node(char data) {
        this->data = data;
        this->isTerminal = false;
    }
};


class Trie {
    public:
    Node* root;
    Trie() {
        root = new Node('\0');
    }

    void insert(string word) {
        Node* temp = root;
        for(int i = 0; i < word.size(); i++) {
            char ch = word[i];
            if(temp->child.count(ch) == 0) {
                temp->child[ch] = new Node(ch);
            }
            temp = temp->child[ch];
        }
        temp->isTerminal = true;
    }

    bool search(string word) {
        Node* temp = root;
        for(int i = 0; i < word.size(); i++) {
            char ch = word[i];
            if(temp->child.count(ch) == 0) {
                return false;
            }
            temp = temp->child[ch];
        }
        return temp->isTerminal;
    }
};


void printWords(vector<vector<char>> &mat, int i, int j, string word, vector<vector<bool>> &visited, Trie &trie) {
    int n = mat.size();
    int m = mat[0].size();


    if(i < 0 || j < 0 || i >= n|| j >= m || visited[i][j] == true) {
        return;
    }

    visited[i][j] = true;
    word += mat[i][j];
    if(trie.search(word)) {
        cout << word << endl;
    }
    int dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
    int dy[] = {1, -1, 0, 0, 1, -1, -1, 1};

    for(int k = 0; k < 8; k++) {
        int nrow = i + dx[k];
        int ncol = j + dy[k];
        printWords(mat, nrow, ncol, word, visited, trie);
    }
    visited[i][j] = false;
}

int main() {

    vector<string> words = { "tea",  "nab", "snack"};

    vector<vector<char>> mat = {
      {'c','n','t'},
      {'k','a','e'},
      {'e','b','k'},
    };
    
    int n = mat.size();
    int m = mat[0].size();

    
    Trie trie;
    for(string word : words) {
        trie.insert(word);
    }
     
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printWords(mat, i, j, "", visited, trie);
        }
    }



    

    return 0;
}