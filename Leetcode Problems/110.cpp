#include <bits/stdc++.h>
using namespace std;

// TreeNode definition (same as LeetCode)
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
    int height(TreeNode* root, bool& ans) {
        if (root == NULL) return 0;

        int leftHeight = height(root->left, ans);
        int rightHeight = height(root->right, ans);

        if (abs(leftHeight - rightHeight) > 1)
            ans = false;

        return max(leftHeight, rightHeight) + 1;
    }

    bool isBalanced(TreeNode* root) {
        bool ans = true;
        height(root, ans);
        return ans;
    }
};

int main() {
    // Build a sample binary tree:
    //         1
    //        / \
    //       2   3
    //      / \
    //     4   5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    // root->left->left->left = new TreeNode(8); // Uncomment to make it unbalanced

    Solution sol;
    bool result = sol.isBalanced(root);

    cout << (result ? "Tree is balanced " : "Tree is NOT balanced ") << endl;

    return 0;
}
