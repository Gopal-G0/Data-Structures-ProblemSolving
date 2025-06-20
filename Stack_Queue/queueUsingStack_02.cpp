#include<bits/stdc++.h>
using namespace std;

class Queue {
    public:
        stack<int> st1,st2;
        int n = 0;

        void push(int val) {
            st1.push(val);
            n++;
        }

        int pop() {
            int value;
            if(!st2.empty()) {
                st2.pop();
            }

            else {
                while(st1.size()) {
                    st2.push(st1.top());
                    st1.pop();
                }
                value = st2.top();
                st2.pop();
            }

            return value;
        }

        int front() {
            if(!st2.empty()) {
                return st2.top();
            }

            else {
                while(st1.size()) {
                    st2.push(st1.top());
                    st1.pop();
                }
            }
            return st2.top();
        }

        int getSize() {
            return n;
        }
};

int main() {
    
    Queue que;

    que.push(5);
    que.push(7);
    que.push(9);
    que.push(0);
    que.push(1);
    que.push(4);
    que.push(2);

    cout << "Size of Queue : " << que.getSize() << endl;
    cout << "Top/Front of Queue : " << que.front() << endl;

    return 0;
}

