class ArrayStack {

private:
    int st[10];
    int topIndex;
    int size;

public:
    ArrayStack() {
        topIndex = -1;
        size = 0;
    }
    
    void push(int x) {
        if(topIndex >= 9) return;
        topIndex = topIndex + 1;
        st[topIndex] = x;
        size += 1;
    }
    
    int pop() {
        if(topIndex == -1) return -1;
        int val = st[topIndex];
        topIndex -= 1;
        size -= 1;
        return val;
    }
    
    int top() {
        if(topIndex == -1) return -1;
        return st[topIndex];
    }
    
    bool isEmpty() {
        return size == 0;
    }
};
