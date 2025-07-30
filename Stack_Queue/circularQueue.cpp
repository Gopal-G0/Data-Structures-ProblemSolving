#include<iostream>
using namespace std;

class circularQueue {
    private:
        int* queue;
        int size;
        int front;
        int rear;

    public:
        //Constructor
        circularQueue(int s) {
            size = s;
            queue = new int[s];
            front = -1;
            rear = -1;
        }

        //Destructor --> to free space after use
        ~circularQueue() {
            delete[] queue;
        }

        bool isFull() {
            return (rear + 1) % size == front;
        }

        bool isEmpty() {
            return front == -1;
        }

        void enqueue(int val) {
            if(isFull()) {

                cout << "Queue OverFlow: Cannot add element." << endl;
                return;
            }

            else if(isEmpty()) {
                front = 0;
            }

            rear = (rear + 1) % size;
            queue[rear] = val;

            cout << "Enqueued: " << val << endl;
        }

        int dequeue() {
            
            if(isEmpty()) {

                cout << "Queue underflow: Cannot remove element." << endl;
                return -1;
            }

            int dequeuedItem = queue[front];

            //if there was only one element
            if(front == rear) {
                front = -1;
                rear = -1;

            } else {

                front = (front + 1) % size;
            }

            cout << "Dequeued: " << dequeuedItem << endl;
            return dequeuedItem;
        }

        int getFront() {
            if(isEmpty()) {
                cout << "Queue is Empty." << endl;
                return -1;
            }

            return queue[front];
        }

        int getRear() {

            if(isEmpty()) {
                cout << "Queue is Empty." << endl;
                return -1;
            }

            return queue[rear];
        }

        void printQueue() {

            if(isEmpty()) {
                cout << "Queue is Empty." << endl;
                return;
            }

            cout << "Queue Elements : ";
            if(rear >= front) {
                for(int i = front;i <= rear;i++) {
                    cout << queue[i] << " ";
                }

            } else {

                for(int i = front;i < size;i++) {
                    cout << queue[i] << endl;
                }

                for(int i = 0;i <= rear;i++) {
                    cout << queue[i] << endl;
                }
            }

            cout << endl;
        }
 };

int main() {
    circularQueue cQueue(10);

    cQueue.enqueue(3);
    cQueue.enqueue(6);
    cQueue.enqueue(0);
    cQueue.enqueue(1);
    cQueue.enqueue(2);

    cout << endl;

    cQueue.dequeue();

    cout << endl;

    cQueue.printQueue();
    cout << endl;
    cout << "Front of queue: " << cQueue.getFront() << endl;

    cout << endl;

    cQueue.printQueue();

    cout << endl;
    cout << "Rear of queue: " << cQueue.getRear() << endl;

    return 0;
}