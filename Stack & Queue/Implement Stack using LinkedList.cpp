struct Node{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

class LinkedListStack {
private:
    Node* topIdx;
    int size;

public:
    LinkedListStack() {
        size = 0;
        topIdx = NULL;
    }
    
    void push(int x) {
        Node* temp = new Node(x);
        temp -> next = topIdx;
        topIdx = temp;
        size += 1;
    }
    
    int pop() {
        Node* temp = topIdx;
        topIdx = topIdx->next;
        int val = temp->data;
        delete temp;
        size -= 1;
        return val;
    }
    
    int top() {
        return topIdx->data;
    }
    
    bool isEmpty() {
        return topIdx == NULL;
    }
};
