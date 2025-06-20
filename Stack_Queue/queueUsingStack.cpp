#include<bits/stdc++.h>
using namespace std;

class Queue {
    stack<int> st1,st2;

    void push(int val) {
        while(st1.size()) {
            st2.push(st1.top());
            st1.pop();
        }
        st1.push(val);
        while(st2.size()) {
            st1.push(st2.top());
            st2.pop();
        }
    } 
    
    int front() {
        return st1.top();
    }

    int pop() {
        st1.pop();
    }
    
};

int main() {
    return 0;
}