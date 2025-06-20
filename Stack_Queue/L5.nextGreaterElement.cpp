#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums) {
    vector<int> nge(nums.size());
    stack<int> st;

    for(int i = nums.size() - 1;i >= 0;i--) {

        while(!st.empty() && st.top() <= nums[i]) {
            st.pop();
        }

        if(st.empty()) {
            nge[i] = -1;
        }

        else {
            nge[i] = st.top();
        }

        st.push(nums[i]);
    }

    return nge;
}

int main() {
    vector<int> nums = {4,12,5,3,1,2,5,3,1,2,4,6};
    vector<int> res = nextGreaterElement(nums);
    cout << "Next Greater Elements are : ";

    for(int num : res) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;

}