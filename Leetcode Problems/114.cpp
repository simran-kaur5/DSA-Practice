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
    TreeNode* nextRight = NULL;

    void flatten(TreeNode* root) {
        if (root == NULL) return;

        // Reverse preorder: right → left → root
        flatten(root->right);
        flatten(root->left);

        root->left = NULL;
        root->right = nextRight;
        nextRight = root;
    }
};

// Helper function to print flattened linked list
void printFlattened(TreeNode* root) {
    cout << "Flattened tree (linked list form): ";
    while (root) {
        cout << root->val << " ";
        root = root->right;
    }
    cout << endl;
}

int main() {
    // Build sample binary tree:
    //        1
    //       / \
    //      2   5
    //     / \   \
    //    3   4   6

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    Solution sol;
    sol.flatten(root);

    printFlattened(root);

    return 0;
}
