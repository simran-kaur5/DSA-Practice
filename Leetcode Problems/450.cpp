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
    // Find the smallest value node in the right subtree
    TreeNode* findMin(TreeNode* root) {
        while (root && root->left != NULL) {
            root = root->left;
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return NULL;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            // Node found — handle 3 possible cases

            // Case 1: No children
            if (root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            }

            // Case 2: One child
            else if (root->left == NULL || root->right == NULL) {
                TreeNode* child = (root->left) ? root->left : root->right;
                delete root;
                return child;
            }

            // Case 3: Two children
            else {
                TreeNode* successor = findMin(root->right);
                root->val = successor->val;
                root->right = deleteNode(root->right, successor->val);
            }
        }

        return root;
    }
};

// Helper functions for testing
TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    Solution sol;
    TreeNode* root = NULL;

    // Example: create BST
    vector<int> vals = {5, 3, 6, 2, 4, 7};
    for (int v : vals) root = insert(root, v);

    cout << "Original tree (inorder): ";
    inorder(root);
    cout << endl;

    int key = 3;
    cout << "Deleting node with key = " << key << endl;
    root = sol.deleteNode(root, key);

    cout << "After deletion (inorder): ";
    inorder(root);
    cout << endl;

    return 0;
}
