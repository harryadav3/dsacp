#include <iostream>
#include <unordered_map>
using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
    }
};

class WordMemory {
private:
    TrieNode* root;

public:
    WordMemory() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* curr = root;
        for (char ch : word) {
            if (curr->children.find(ch) == curr->children.end()) {
                curr->children[ch] = new TrieNode();
            }
            curr = curr->children[ch];
        }
        curr->isEndOfWord = true;
    }

    int findPartial(string partialWord) {
        TrieNode* curr = root;
        for (char ch : partialWord) {
            if (curr->children.find(ch) == curr->children.end()) {
                return 0;
            }
            curr = curr->children[ch];
        }
        return countWords(curr);
    }

private:
    int countWords(TrieNode* node) {
        int count = 0;
        if (node->isEndOfWord) {
            count++;
        }
        for (auto it = node->children.begin(); it != node->children.end(); ++it) {
            count += countWords(it->second);
        }
        return count;
    }
};

int main() {
    int P;
    cin >> P;

    WordMemory wordMemory;
    while (P--) {
        string operation, word;
        cin >> operation >> word;
        if (operation == "add") {
            wordMemory.addWord(word);
        } else if (operation == "find") {
            cout << wordMemory.findPartial(word) << endl;
        }
    }

    return 0;
}
