

struct Node {

    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
}


struct Stack {

    Node* head;
    int size;

    Stack() {
        head = NULL;
        size = 0;
    }

    void push(int data)[

        Node *nn = new Node(data);
        nn->next = head;
        head = nn;
        
    ]
}