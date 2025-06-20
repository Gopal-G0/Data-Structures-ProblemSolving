#include<bits/stdc++.h>
using namespace std;

class Queue {
    private:
        class Node {
        public:
            int data;
            Node* next;

            Node(int d) {
                data = d;
                next = NULL;
            }
        };
    
    public:
        Node* start;
        Node* end;
        int size;

        Queue() {
            start = NULL;
            end = NULL;
            size = 0;
        }

        ~Queue() {
            while(!isEmpty()) {
                pop();
            }
        }

        void push(int value) {
            Node* newNode = new Node(value);
            if(start == NULL) {
                start = end = newNode;
            }

            else {
                end -> next = newNode;
                end = newNode;
            }

            size++;
        }

        int pop() {
            if(start == NULL) {
                cout << "Queue is Empty" << endl;
            }

            Node* temp = start;
            int value = temp -> data;
            start = start -> next;
            delete temp;
            size--;

            return value;
        }

        int peek() {
            if(start == NULL) {
                cout << "Queue is Empty" << endl;
            }

            return start -> data;
        }

        int getSize() {
            return size;
        }

        bool isEmpty() {
            return start == NULL;
        }
};

int main() {
    Queue que;

    que.push(4);
    que.push(1);
    que.push(2);
    que.push(5);
    que.push(8);
    que.push(0);
    que.push(7);

    cout << "Size of Queue : " << que.getSize() << endl;
    cout << "Top/First Value of Queue : " << que.peek() << endl;
    cout << endl;
    //printing Queue Elements
    while(!que.isEmpty()) {
        cout << que.pop() << " ";
    }
    cout << endl;
    return 0;
}