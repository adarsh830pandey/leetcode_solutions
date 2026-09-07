class MyCircularQueue {
public:
    int *arr;
    int n;
    int front;
    int rear;

    MyCircularQueue(int k) {
        arr = new int[k];
        n = k;
        front = -1;
        rear = -1;
    }

    bool enQueue(int value) {

        // Empty case
        if (front == -1 && rear == -1) {
            front = 0;
            rear = 0;
            arr[rear] = value;
            return true;
        }

        // Full condition
        if (front==0 && rear==n-1 || rear==front-1) {
            return false;
        }

        // Circular case
        if (rear == n - 1) {
            rear = 0;
        }
        else {
            rear++;
        }

        arr[rear] = value;

        return true;
    }

    bool deQueue() {

        // Empty case
        if (front == -1 && rear == -1) {
            return false;
        }

        // Single element
        if (front == rear) {
            front = -1;
            rear = -1;
            return true;
        }

        // Circular case
        if (front == n - 1) {
            front = 0;
        }
        else {
            front++;
        }

        return true;
    }

    int Front() {
        if (front == -1) {
            return -1;
        }

        return arr[front];
    }

    int Rear() {
        if (rear == -1) {
            return -1;
        }

        return arr[rear];
    }

    bool isEmpty() {
        return front == -1 && rear == -1;
    }

    bool isFull() {
        return (rear + 1) % n == front;
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