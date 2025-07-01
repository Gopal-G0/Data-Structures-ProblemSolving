#include<bits/stdc++.h>
using namespace std;

int totalTrappedWater(vector<int>& arr) {
    int n = arr.size();
    int leftMax = 0;
    int rightMax = 0;
    int total = 0;
    int left = 0;
    int right = n-1;

    while(left < right) {
        if(arr[left] <= arr[right]) {

            if(leftMax > arr[left]) {
                total += leftMax - arr[left];
            }

            else {
                leftMax = arr[left];
            }

            left++;
        }

        else {

            if(rightMax > arr[right]) {
                total += rightMax - arr[right];
            }

            else {
                rightMax = arr[right];
            }

            right--;
        }
    }

    return total;
}

int main() {
    vector<int> arr = {1,3,2,0,4,3,0,1};

    cout << "Total Trapped Water : " << totalTrappedWater(arr) << endl;
    return 0;
}
