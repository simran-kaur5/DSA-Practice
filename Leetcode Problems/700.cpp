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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == NULL) {
            return NULL;
        }

        if (root->val == val) {
            return root;
        }
        if (root->val > val) {
            return searchBST(root->left, val);
        }
        return searchBST(root->right, val);
    }
};

// Helper function to print subtree inorder
void printInorder(TreeNode* root) {
    if (root == NULL) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    // Build sample BST
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

    int val = 2;
    Solution sol;
    TreeNode* result = sol.searchBST(root, val);

    if (result != NULL) {
        cout << "Node found with value " << val << endl;
        cout << "Inorder of subtree starting at node " << val << ": ";
        printInorder(result);
        cout << endl;
    } else {
        cout << "Value " << val << " not found" << endl;
    }

    return 0;
}
