#include<bits/stdc++.h>
using namespace std;

class Stack {
    private:
        //Node class for LinkedList
        class Node {
        public:
            int data;
            Node* next;
            //constructor
            Node(int d) {
                data = d;
                next = NULL;
            }
        };

    public:
        Node* Top;
        int size;
        //constructor for stack
        Stack() {
            size = 0;
            Top = NULL;
        }    

        //Destructor
        ~Stack() {
            while(!isEmpty()) {
                pop();
            }
        }

        void push(int val) {
            Node* newNode = new Node(val);
            newNode -> next = Top;
            Top = newNode;
            size = size + 1;
        }

        int pop() {
            if(isEmpty()) {
                cout << "Stack is Empty" << endl;
            }

            Node* temp = Top;
            int value = temp -> data;
            Top = Top -> next ;
            delete temp;
            size--;
            return value;
        }

        int getSize() {
            return size;
        }

        int top() {
            if(isEmpty()) {
                cout << "Stack is Empty" << endl;
            }

            return Top -> data;
        }

        bool isEmpty() {
            return size == 0;
        }
};

int main() {
    Stack st;

    st.push(3);
    st.push(7);
    st.push(2);
    st.push(8);
    st.push(1);

    cout << "Size of Stack : " << st.getSize() << endl;
    cout << "Top of Stack : " << st.top() << endl;
    cout << endl;

    //printing stack elements
    while(!st.isEmpty()) {
        cout << st.pop() << " ";
    }
    cout << endl;
    return 0;
}