class ArrayQueue {

private:
    int q[10];
    int start;
    int end;
    int currSize;

public:
    ArrayQueue() {
        start = -1;
        end = -1;
        currSize = 0;
    }
    
    void push(int x) {
        if(currSize == 10) return;
        if(currSize == 0)
            start = end = 0;
        else
            end = (end + 1) % 10;
        q[end] = x;
        currSize += 1;
    }
    
    int pop() {
        if(currSize == 0) return -1;
        int el = q[start];
        if(currSize == 1)
            start = end = -1;
        else
            start = (start + 1)% 10;
        currSize -= 1;
        return el;
    }
    
    int peek() {
        if(currSize == 0) return 0;
        return q[start];
    }
    
    bool isEmpty() {
        return currSize == 0;
    }
};
