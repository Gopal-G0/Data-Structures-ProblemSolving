#include<bits/stdc++.h>
using namespace std;

vector<int> rightIndices(vector<int> &heights)
{
    int n = heights.size();
    vector<int> ans(n);
    stack<pair<int,int>> st;
    for (int i = n - 1; i >= 0; i--)
    {

        if (st.empty())
        {
            ans[i] = -1;
        }

        else if (st.size() > 0 && st.top().first < heights[i])
        {
            ans[i] = st.top().second;
        }

        else if (st.size() > 0 && st.top().first >= heights[i])
        {

            while (st.size() > 0 && st.top().first >= heights[i])
            {
                st.pop();
            }

            if (st.empty())
                ans[i] = -1;

            else
                ans[i] = st.top().second;
        }

        st.push({heights[i],i});
    }

    return ans;
}

vector<int> leftIndices(vector<int> &heights)
{
    int n = heights.size();
    vector<int> ans(n);
    stack<pair<int,int>> st;
    for (int i = 0; i < n; i++)
    {

        if (st.empty())
        {
            ans[i] = -1;
        }

        else if (st.size() > 0 && st.top().first < heights[i])
        {
            ans[i] = st.top().second;
        }

        else if (st.size() > 0 && st.top().first >= heights[i])
        {

            while (st.size() > 0 && st.top().first >= heights[i])
            {
                st.pop();
            }

            if (st.empty())
                ans[i] = -1;

            else
                ans[i] = st.top().second;
        }

        st.push({heights[i],i});
    }

    return ans;
}

int main() {
    vector<int> heights = {1,4,6,8,5,6,7,2,3,0,3};

    vector<int> left = leftIndices(heights);

    vector<int> right = rightIndices(heights);
    
    cout << "diff between right & left idx : ";
    for(int i = 0;i < heights.size();i++) {
        int width = right[i] - left[i] - 1;
        cout << right[i] - left[i] << " ";
    }
    cout << endl;
    cout << endl;
    
    cout << "width corresponds to every height : ";
    for(int i = 0;i < heights.size();i++) {
        int width = right[i] - left[i] - 1;
        cout << width << " ";
    }
    cout << endl;
    cout << endl;
    
    cout << "Area of rectangle for every height : ";
    for(int i = 0;i < heights.size();i++) {
        int width = right[i] - left[i] - 1;
        int area = width * heights[i];
        cout << area << " ";
    }
    cout << endl;
    
}