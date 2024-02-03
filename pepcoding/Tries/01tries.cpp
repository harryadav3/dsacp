#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    Node* left;
    Node* right;
};


class Trie {
    public:
    Node* root;
    Trie(){
        root = new Node();
    }

    void insert(int no){

        Node* temp = root;
        for( int i=31; i>= 0; i-- ) {
            int bit = (no>>i) & 1;

            if( bit == 0 ) {
                if( temp->left == NULL ) {
                    temp->left = new Node();
                }
                temp = temp->left;
            } else {
                if( temp->right == NULL ) {
                    temp->right = new Node();
                }
                temp = temp->right;
            }
        }
    }
    int search(int a) {

        Node* temp =  root;
        int value = 0;
        for( int i=31; i>=0; i-- ) {
            int bit = (a>>i) & 1;

            if( bit == 0 ) {
                if( temp->right != NULL ) {
                    temp = temp->right;
                    value += (1<<i);
                } else {
                    temp = temp->left;
                }
            } else {
                if( temp->left != NULL ) {
                    temp = temp->left;
                    value += (1<<i);
                } else {
                    temp = temp->right;
                }
            }
        }
    }
};


int main() {

   int input[] = {3, 7, 2, 8, 5};
   Trie t;
    for( int i=0; i<5; i++ ) {
         t.insert(input[i]);


    int ans   =  0;
    for( auto a : input) {
        maxxor = t.search(a);
        ans = max(ans, maxxor);
    }



    return 0;
}