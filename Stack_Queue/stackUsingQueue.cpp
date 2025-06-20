#include<bits/stdc++.h>
using namespace std;

class Stack {
    public:
        queue<int> que;

        void push(int val) {
            int n;
            n = que.size();
            que.push(val);

            for(int i = 1; i <= n;i++) {
                que.push(que.front());
                que.pop();
            }
        }

        int pop() {
            int value = que.front();
            que.pop();

            return value;
        }

        int top() {
            return que.front();
        }

        int getSize() {
            return que.size();
        }
};

int main() {
    Stack st;

    st.push(9);
    st.push(4);
    st.push(0);
    st.push(1);
    st.push(3);
    st.push(5);

    cout << "Size of Stack : " << st.getSize() << endl;
    cout << "Top of Stack : " << st.top() << endl;
    return 0;
}