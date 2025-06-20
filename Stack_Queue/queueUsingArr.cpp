#include<bits/stdc++.h>
using namespace std;

class Queue {
    private:
        int start;
        int end;
        int currSize;
        int capacity;
        int *arr;

    public:
        Queue(int size) {
            arr = new int[size];
            currSize = 0;
            capacity = size;
            start = -1;
            end = -1;
        }

        ~Queue() {
            delete[] arr;
        }

        void push(int element) {
            if(currSize == capacity) {
                cout << "Queue is Full." << endl;
            }

            else if(currSize == 0) {
                start = 0,end = 0;
            }

            else {
                end = (end + 1) % capacity;
            }
            arr[end] = element;
            currSize += 1;
        }

        int pop() {
            int element = arr[start];

            if(currSize == 0) {
                cout << "There is nothing to pop out.." << endl;
            }

            else if(currSize == 1) {
                start = end = -1;
            }

            else {
                start = (start + 1) % capacity;
            }

            currSize -= 1;
            return element;
        }

        int top() {
            if(currSize == 0) {
                cout << "Queue is Empty.." << endl;
                return -1;
            }

            return arr[start];
        }

        int back() {
            return arr[end];
        }

        int size() {
            return currSize;
        }
};

int main() {
    Queue que(10);

    que.push(1);
    que.push(2);
    que.push(3);
    que.push(4);
    que.push(5);

    cout << "Size of Queue : " << que.size() << endl;
    cout << "Top of Queue : " << que.top() << endl;
    cout << "Back/End of Queue : " << que.back() << endl;
    return 0;
}