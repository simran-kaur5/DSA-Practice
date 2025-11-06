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


// Helper function to insert nodes into BST
TreeNode* insert(TreeNode* root, int val) {
    if (root == nullptr)
        return new TreeNode(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}


int main() {
   

    TreeNode* bst1 = nullptr;
    vector<int> vals1 = {5,3,7,2,4,6,8};
    for (int v : vals1) bst1 = insert(bst1, v);

    TreeNode* bst2 = nullptr;
    vector<int> vals2 = {10,6,15,3,8,11,18};
    for (int v : vals2) bst2 = insert(bst2, v);

    return 0;
}
