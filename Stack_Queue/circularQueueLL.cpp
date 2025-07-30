#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int d) : data(d), next(nullptr) {}
};

class circularQueue {
    private:
        Node* front;
        Node* rear;
    
    public:
        circularQueue() {
            front = nullptr;
            rear = nullptr;
        }

        bool isEmpty() {

            return front == nullptr;
        }

        void enqueue(int val) {
            Node* newNode = new Node(val);
            if(isEmpty()) {
                front = newNode;
            }

            else {

                rear -> next = newNode;
            }

            rear = newNode;
            rear -> next = front;
            cout << "Enqueue: " << val << endl;
        }

        int dequeue() {

            if(isEmpty()) {
                cout << "Queue underflow.Cannot remove element" << endl;
                return -1;
            }

            Node* temp = front;
            int dequeuedItem = temp -> data;

            if(front == rear) {

                front = nullptr;
                rear = nullptr;

            } else {

                front = front -> next;
                rear -> next = front;
            }

            delete temp;
            cout << "Dequeued: " << dequeuedItem << endl;
            return dequeuedItem;
        }

        void printQueue() {

            if(isEmpty()) {
                cout << "Queue is Empty." << endl;
                return;
            }

            cout << "Queue Elements : ";
            Node* temp = front;

            do {
                cout << temp -> data << " ";
                temp = temp -> next;

            } while(temp != front);

            cout << endl;
        }
};

int main() {
    circularQueue cQueue;
    cQueue.enqueue(4);
    cQueue.enqueue(1);
    cQueue.enqueue(6);
    cQueue.enqueue(0);
    cQueue.enqueue(2);

    cout << endl;

    cQueue.dequeue();

    cQueue.printQueue();
    return 0;
}