#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    char data;
    unordered_map<char, Node *> child;
    bool isTerminal;

    Node(char data)
    {
        this->data = data;
        isTerminal = false;
    }
};

class Trie
{
    // Data members;
    Node *root;
public:
    Trie()
    {
        root = new Node('\0');
    }

    // methods

    void addWord(string word)
    {
        Node *temp = root;
        for (auto ch : word)
        {
            if (temp->child.count(ch) == 0)
            {
                temp->child[ch] = new Node(ch);
                temp = temp->child[ch];
            }
            else
            {
                temp = temp->child[ch];
            }
        }
        root->isTerminal = true;
    }
    bool search(string word)
    {
        Node *temp = root;
        for (auto ch : word)
        {
            if (temp->child.count(ch) == 0)
            {
            temp = temp->child[ch];
            }
            else
            {
            return false;
            }

        
         }
        return temp->isTerminal;

    }

    void suggestHelper(Node *temp, string prfix, vector<string> &ans)
    {
        if (temp->isTerminal)
        {
            ans.push_back(prfix);
        }
        for (auto ch : temp->child)
        {
            suggestHelper(ch.second, prfix + ch.first, ans);
        }
    }

    vector<string> suggest(string prfix) {
        Node *temp = root;
        for (auto ch : prfix)
        {
            if (temp->child.count(ch) == 0)
            {
                temp = temp->child[ch];
            }
            else
            {
                return {};
            }
        }
        vector<string> ans;
        suggestHelper(temp, prfix, ans);
        return ans;
    }
};

int main()
{

    Trie t;
    string words[] = {"a", "hello", "not", "news", "apple"};

    for (auto word : words)
    {
        t.addWord(word);
    }

    string searchWord = "not";
    cout << t.search(searchWord) << endl;
    return 0;
}