

#include <bits/stdc++.h>
using namespace std;

template <typename T>

struct Stack {
    

    struct node {
        T  val;
        node* next ;
        node() {
            this->next = NULL;
        }
        node ( T _val) {
            this->val = _val;
            this->next = NULL;
        }
    }

    node *head = NULL;

    void push( T x) {
        node *temp = new node(x);
        temp->next = head;
        head = temp;
    }

    T top() {
        if( head == NULL) {
            cout << "Stack underflow" << endl;
            return -1;
        }
        return head->val;

    }

    void pop() {
        node *temp = head;
        head = head->nxt;
        delete temp;
    }
}

int main() {


    Stack<int> st;
    st.push(1);

    

    return 0;
}