#include<bits/stdc++.h>
using namespace std;

vector<int> firstNegative(vector<int>& arr, int k) {

    int n = arr.size();
    int left = 0;
    int right = k - 1;
    vector<int> res;

    while(right <= n - 1) {
        for(int i = left;i <= right;i++) {

            if(arr[i] < 0) {
                res.push_back(arr[i]);
                break;
            }

            else {
                res.push_back(0);
                
            }
        }

        left++;
        right++;
    }

    return res;
}

int main() {
    vector<int> arr = {-8, 2, 3, -6, 10};

    vector<int> result = firstNegative(arr,2);

    for(int num : result) {

        cout << num << " ";
    }

    cout << endl;

    return 0;
}