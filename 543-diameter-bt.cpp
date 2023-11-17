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

int diameter = 0;

int maxDepth(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    diameter = max(diameter, leftDepth + rightDepth);

    return 1 + max(leftDepth, rightDepth);
}

int diameterOfBinaryTree(TreeNode* root) {
    maxDepth(root);
    return diameter;
}

int main() {
    //
    
    return 0;
}