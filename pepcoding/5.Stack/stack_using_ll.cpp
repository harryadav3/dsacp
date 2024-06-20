#include<bits/stdc++.h>
using namespace std;


class Node {
    public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};


class Stack {

    Node* head;
    int size;
    // this is the constructor
    public:
    Stack() {
        head = NULL;
        size = 0;
    }
    // push mehtod to push the data into the stack 
    // we are maintaiing the head pointer to the top of the stack
    void push(int data) {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
        size++;
    }
    // now do the push instead of using pointer we will use node

    int pop() {
        if( size == 0) {
            cout << "Stack underflow" << endl;
            return -1;
        }

        int data = head->data;
        Node* temp = head;
        head = head->next;
        delete temp; // not necessary in c++ but good practice
        size--;
        return data;
    }

    int top() {
        if( size == 0) {
            cout << "Stack underflow" << endl;
            return -1;
        }

        return head->data;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }


};


int main() {

    Stack s;
    s.push(10); 
    s.push(20);
    s.push(30);


    cout << s.top() << endl;
    cout << s.pop() << endl;
    cout << s.top() << endl;
    cout << s.pop() << endl;
    cout << s.top() << endl;
    cout << s.pop() << endl;


    cout << s.isEmpty() << endl;
    cout << s.getSize() << endl;
}