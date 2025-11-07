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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // Base case: found the place to insert
        if (root == NULL) {
            return new TreeNode(val);
        }

        // Use BST property
        if (val < root->val) {
            root->left = insertIntoBST(root->left, val);
        } else {
            root->right = insertIntoBST(root->right, val);
        }

        return root;
    }
};

// Helper function to print BST inorder
void printInorder(TreeNode* root) {
    if (root == NULL) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    // Build sample BST:
    //         4
    //       /   \
    //      2     7
    //     / \
    //    1   3
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    cout << "Inorder before insertion: ";
    printInorder(root);
    cout << endl;

    int val = 5;
    Solution sol;
    root = sol.insertIntoBST(root, val);

    cout << "Inorder after inserting " << val << ": ";
    printInorder(root);
    cout << endl;

    return 0;
}
