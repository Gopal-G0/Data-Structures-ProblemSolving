#include<bits/stdc++.h>
using namespace std;

class Queue {
    
    int* arr;
    int front;
    int rear;
    int capacity;
    int size;

    public:
        Queue(int capacity) {
            arr = new int[capacity];
            front = 0;
            rear = 0;
            size = 0;
        }

        void enqueue(int val) {
            if(rear == capacity - 1) {
                cout << "OverFlow,Queue is Full" << endl;
            }

            else {
                arr[rear++] = val;
                size++;
                cout << val << " added to the queue " << endl;
            }
        }

        int dequeue() {
            if(front == rear) {
                cout << "UnderFlow, Queue is Empty." << endl;
            }

            int ans = arr[front];

            arr[front] = -1;
            front++;
            size--;
            if(front == rear) {
                front = 0;
                rear  = 0;
            }

            cout << ans << " removed from the queue " << endl;

            return ans;  
        }

        int getFront() {
            if(front == rear) {
                cout << "Queue is Empty." << endl;
            }

            return arr[front];
        }

        bool isEmpty() {
            if(front == rear) {
                return true;
            }

            return false;
        }

        bool isFull() {
            if(rear == capacity - 1) {
                return true;
            }

            return false;
        }

        int getSize() {
            return size;
        }
};

int main() {

    Queue que = Queue(10);

    que.enqueue(3);
    que.enqueue(7);
    que.enqueue(5);
    que.enqueue(9);
    que.enqueue(2);

    que.dequeue();

    cout << "Size of the queue : " << que.getSize() << endl;
    cout << "Front of queue : " << que.getFront() << endl;

    return 0;
}