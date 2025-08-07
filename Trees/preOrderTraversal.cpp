#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) {

        data = val;
        left = right = nullptr;
    } 
};

int main() {

    TreeNode* root = new TreeNode(1);

    root -> left = new TreeNode(2);
    root -> right = new TreeNode(3);

    return 0;
}