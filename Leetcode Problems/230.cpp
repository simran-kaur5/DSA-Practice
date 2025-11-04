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

class Solution {
public:
    int kth(TreeNode* root, int &i, int &k) {
        if (root == NULL) {
            return -1;
        }

        int left = kth(root->left, i, k);
        if (left != -1) {
            return left;
        }

        i++;
        if (i == k) {
            return root->val;
        }

        return kth(root->right, i, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        int i = 0;
        return kth(root, i, k);
    }
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

// MAIN FUNCTION
int main() {
    Solution sol;

    // Build a sample BST:
    //         5
    //        / \
    //       3   7
    //      / \   \
    //     2   4   8

    TreeNode* root = nullptr;
    vector<int> values = {5, 3, 7, 2, 4, 8};
    for (int val : values) {
        root = insert(root, val);
    }

    int k = 3;
    cout << "The " << k << " smallest element is: " << sol.kthSmallest(root, k) << endl;

    return 0;
}
