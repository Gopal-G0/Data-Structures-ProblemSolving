#include<bits/stdc++.h>
using namespace std;

vector<int> leftIndices(vector<int> &heights)
{
    int n = heights.size();
    vector<int> ans(n);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {

        if (st.empty())
        {
            ans[i] = -1;
        }

        else if (st.size() > 0 && st.top() < heights[i])
        {
            ans[i] = st.top();
        }

        else if (st.size() > 0 && st.top() >= heights[i])
        {

            while (st.size() > 0 && st.top() >= heights[i])
            {
                st.pop();
            }

            if (st.empty())
                ans[i] = -1;

            else
                ans[i] = st.top();
        }

        st.push(heights[i]);
    }

    return ans;
}

int main() {
    vector<int> heights = {1,4,6,8,5,6,7,2,3,0,3};

    vector<int> result = leftIndices(heights);

    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;
}