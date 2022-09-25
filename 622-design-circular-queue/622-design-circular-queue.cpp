class MyCircularQueue {
    vector<int> q;
    int front;
    int size;
    int k;
public:
    MyCircularQueue(int k): q(k), front(0), size(0), k(k) { }
    
    bool enQueue(int value) {
        if(isFull()) {
            return false;
        }
        q[(front + size) % k] = value;
        ++size;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        front = (front + 1) % k;
        --size;
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : q[front];
    }
    
    int Rear() {
        return isEmpty() ? -1 : q[(front + size - 1) % k];
    }
    
    bool isEmpty() {
        return !size;
    }
    
    bool isFull() {
        return size == k;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */