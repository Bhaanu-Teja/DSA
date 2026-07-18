struct Node{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

class LinkedListQueue {
private:
    Node* start;
    Node* end;
    int size;

public:
    LinkedListQueue() {
        start = NULL;
        end = NULL;
        size = 0;
    }
    
    void push(int x) {
        Node* temp = new Node(x);
        if(start == NULL){
            start = end = temp;
        }
        else{
            end->next = temp;
            end = end->next;
        }
        size += 1;
    }
    
    int pop() {
        if(start != NULL){
            Node* temp = start;
            int val = temp->data;
            start = start->next;
            delete temp;
            size -= 1;
            return val;
        }
        return -1;
    }
    
    int peek() {
        if(start == NULL) return -1;
        return start->data;
    }
    
    bool isEmpty() {
        return size == 0;
    }
};
