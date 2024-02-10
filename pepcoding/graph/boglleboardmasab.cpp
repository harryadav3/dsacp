#include <bits/stdc++.h>

using namespace std;

class Node {
public:
  char data;
  bool isTerminal;
  unordered_map<char, Node *> children;

  Node(char data) {
    this->data = data;
    this->isTerminal = false;
  }
};

class Trie {
public:
  Node *root;

  Trie() { root = new Node('\0'); }

  void addWord(string word) {
    Node *temp = root;
    for (char ch : word) {
      if (temp->children.count(ch)) {
        temp = temp->children[ch];
      } else {
        Node *n = new Node(ch);
        temp->children[ch] = n;
        temp = n;
      }
    }
    temp->isTerminal = true;
  }

  bool search(string word) {
    Node *temp = root;
    for (char ch : word) {
      if (temp->children.count(ch)) {
        temp = temp->children[ch];
      } else {
        return false;
      }
    }
    return temp->isTerminal;
  }
};

int main() {
  string words[4] = {"boggle", "boggle", "boggle", "boggle"};

  char baord[3][3] = {{'g', 'i', 'z'}, {'u', 'e', 'k'}, {'q', 's', 'e'}};

  Trie t;
  for (auto word : words) {
    t.addWord(word);
  }

  bool visited[3][3] = {false};
}
