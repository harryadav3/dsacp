#include <bits/stdc++.h>
using namespace std;



// Define teh Node Structure
struct Node {
    Node *next;
    int data;

    Node( int x ) {
        this->data = x;
        this->next = nullptr;
    }
};

Node* insertAtHead( Node *head, int x) {
    Node *temp = new Node(x);
    temp->next = head;
    return temp;
}

Node* insertAtTail( Node *head, int x) {
    Node *temp = new Node(x);
    if( head == nullptr) {
        return temp;
    }

    Node *curr = head;
    while( curr->next != nullptr) {
        curr = curr->next;
    }

    curr->next = temp;
    return head;
}


int lengthOfLL( Node *head) {
    Node *curr = head;
    int count = 0;
    while( curr != nullptr) {
        count++;
        curr = curr->next;
    }
    return count;
}


// Cosnturct a linked list 

Node* constructLL() {
    Node *head = nullptr;
    Node *tail = nullptr;

    int n ;
    cin>>n;

    while( n-- ) {
        int x;
        cin>>x;

        Node *temp = new Node(x);

        if( head == nullptr) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    return head;
}

// Display the linked list
void displayLL( Node *head) {
    Node *curr = head;
    while( curr != nullptr) {
        cout<<curr->data<<"->";
        curr = curr->next;
    }
    cout<<"nullptr"<<endl;
}


Node* insertAtK(Node* head, int data ,  int k) {

    if( k == 1) return insertAtHead(head, data);
    if( k > lengthOfLL(head)) return insertAtTail(head, data);

    int count = 1;

    Node* curr = head;

    while( count < k-1) {
        curr = curr->next;
        count++;
    }

    Node* temp = new Node(data);
    temp->next = curr->next;
    curr->next = temp;  

    return head;
}

Node* LeftShiffLLbyK(Node *head, int k) {
    if( k == 0) return head;

    Node *curr = head;
    Node *tail = nullptr;

    while( curr->next != nullptr) {
        curr = curr->next;
    }

    tail = curr;

    curr = head;

    while( k-- ) {
        tail->next = head;
        tail = head;
        head = head->next;
        tail->next = nullptr;
    }

    return head;
}


Node* rightShiftLLbyK(Node *head, int k) {
// write a logic to right shift the ll by k the last k elment should come ot first

    if( k == 0) return head;

    Node *curr = head;
    Node *tail = nullptr;

    while( curr->next != nullptr) {
        curr = curr->next;
    }

    tail = curr;

    curr = head;

    while( k-- ) {
        curr = head;
        while( curr->next != tail) {
            curr = curr->next;
        }
        tail->next = head;
        head = tail;
        tail = curr;
        tail->next = nullptr;
    }

    return head;

}   

Node* deleteAtStart(Node *head) {
    if( head == nullptr) return nullptr;

    Node *temp = head;
    head = head->next;
    delete temp;

    return head;
}

Node* deleteAtEnd(Node *head) {
    if( head == nullptr) return nullptr;

    if( head->next == nullptr) {
        delete head;
        return nullptr;
    }

    Node *curr = head;
    while( curr->next->next != nullptr) {
        curr = curr->next;
    }

    delete curr->next;
    curr->next = nullptr;

    return head;
}


Node* deleteAtK(Node *head, int k) {
    if( k == 1) return deleteAtStart(head);
    if( k == lengthOfLL(head)) return deleteAtEnd(head);

    Node *curr = head;
    int count = 1;

    while( count < k-1) {
        curr = curr->next;
        count++;
    }

    Node *temp = curr->next;
    curr->next = curr->next->next;
    delete temp;

    return head;
}







int main() {

    Node *head = constructLL();

    displayLL(head);

    head = insertAtHead(head, 10);
    displayLL(head);

    head = insertAtTail(head, 20);
    displayLL(head);

    cout<<"Lenght of the Linked List = "<<lengthOfLL(head)<<endl;

    head = insertAtK(head, 30, 3);
    displayLL(head);

    head = LeftShiffLLbyK(head, 2);
    displayLL(head);

    head = rightShiftLLbyK(head, 2);
    displayLL(head);

    head = deleteAtStart(head);
    displayLL(head);

    head = deleteAtEnd(head);
    displayLL(head);

    head = deleteAtK(head, 3);
    displayLL(head);
    


    return 0;
}