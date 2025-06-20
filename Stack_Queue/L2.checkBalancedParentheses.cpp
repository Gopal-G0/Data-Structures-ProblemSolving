#include <bits/stdc++.h>
using namespace std;

bool checkBalanced(string &str)
{
    stack<char> st;

    for (char ch : str)
    {
        if (ch == '(' || ch == '[' || ch == '{')
        {
            st.push(ch);
        }

        else
        {
            if (st.empty())
                return false;

            char chr = st.top();
            

            if ((chr == '(' && ch == ')') ||
                (chr == '[' && ch == ']') ||
                (chr == '{' && ch == '}')) {
                    st.pop();
                }

                else {
                    return false;
                }
        }
    }

    return st.empty();
}

int main() {
    
    string str = "()[(){}]";
    bool res = checkBalanced(str);

    if(res) {
        cout << "Parentheses are Balanced." << endl;
    }

    else {
        cout << "Parentheses are not Balanced" << endl;
    }
    return 0;
}