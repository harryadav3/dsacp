#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) {
        this->val = val;
        this->next = nullptr;
    }
};

// Function to insert a node at the start of the linked list
void insertAtStart(ListNode*& head, int val) {
    ListNode* newNode = new ListNode(val);
    newNode->next = head;
    head = newNode;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(ListNode*& head, int val) {
    ListNode* newNode = new ListNode(val);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    ListNode* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to print the linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    ListNode* head = nullptr;

    insertAtStart(head, 1);  // List: 1 -> nullptr
    insertAtEnd(head, 2);    // List: 1 -> 2 -> nullptr
    insertAtStart(head, 3);  // List: 3 -> 1 -> 2 -> nullptr
    insertAtEnd(head, 4);    // List: 3 -> 1 -> 2 -> 4 -> nullptr

    printList(head);

    return 0;
}
