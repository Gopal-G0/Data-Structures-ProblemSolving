#include <bits/stdc++.h>
using namespace std;

class Stack
{

private:
    int Top;
    int *stack;
    int capacity;

public:
    Stack(int size)
    {
        stack = new int[size];
        Top = -1;
        capacity = size;
    }

    ~Stack()
    {
        delete[] stack;
    }

    int top()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty." << endl;
            return -1;
        }

        return stack[Top];
    }

    void push(int element)
    {
        Top += 1;
        stack[Top] = element;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }

        return stack[Top--];
    }

    bool isEmpty()
    {
        return Top == -1;
    }

    bool isFull()
    {
        return Top == capacity - 1;
    }
};

int main()
{

    Stack st(10);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    st.push(7);
    st.push(8);

    cout << "Top element : " << st.top() << endl;
    cout << "Popped Element : " << st.pop() << endl;
    cout << "Top element : " << st.top() << endl;

}