#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
vector<int> findMode(TreeNode* root) {
    unordered_map<int, int> umap;
    dfs(root, umap);

    int max = 0;
    for(auto it = umap.begin(); it != umap.end(); it++) {
        if(it->second > max) {
            max = it->second;
        }
    }

    vector<int> v;
    for(auto it = umap.begin(); it != umap.end(); it++) {
        if(it->second == max) {
            v.push_back(it->first);
        }
    }

    return v;
}

void dfs(TreeNode* root, unordered_map<int, int>& umap) {
    if(!root) {
        return;
    }
    umap[root->val]++;
    dfs(root->left, umap);
    dfs(root->right, umap);
}

int main() {
    return 0;
}