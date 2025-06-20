#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:
    stack<int> st;
    int mini = INT_MAX;

    void push(int val)
    {
        if (st.empty())
        {
            st.push(val);
            mini = val;
        }

        else
        {
            if (val > mini)
                st.push(val);

            else
            {
                st.push(2 * val - mini);
                mini = val;
            }
        }
    }

    void pop()
    {
        if (st.empty())
        {
            cout << "Stack is Empty" << endl;
        }

        else
        {
            int x = st.top();
            if (x >= mini)
                st.pop();

            else
            {

                mini = 2 * mini - x;
                st.pop();
            }
        }
    }

    int top()
    {
        if (st.empty())
        {
            cout << "Stack is Empty." << endl;
            return 0;
        }

        else
        {
            int x = st.top();
            if (x >= mini)
                return x;
            else
                return mini;
        }

        return 0;
    }

    int getMin()
    {
        return mini;
    }
};

int main()
{

    Stack st;

    st.push(3);
    st.push(5);
    st.push(1);
    st.push(6);
    st.push(9);
    st.push(4);
    st.push(2);

    cout << "Top of Stack : " << st.top() << endl;
    cout << "Min Element in Stack : " << st.getMin() << endl;
    return 0;
}