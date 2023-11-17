#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool balanced = true;

int height(TreeNode* root) {
    if (root == nullptr || !balanced) {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if (abs(leftHeight - rightHeight) > 1) {
        balanced = false;
    }

    return 1 + max(leftHeight, rightHeight);
}

bool isBalanced(TreeNode* root) {
    height(root);
    return balanced; 
}

int main() {
    //
    
    return 0;
}