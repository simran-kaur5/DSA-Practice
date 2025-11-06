#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 */
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
    bool isSame(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        } else if (p == nullptr || q == nullptr) {
            return false;
        }

        if (p->val != q->val) {
            return false;
        }

        return isSame(p->left, q->right) && isSame(p->right, q->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        return isSame(root->left, root->right);
    }
};

// Example test in main() for VS Code
int main() {
    // Create a symmetric tree:
    //       1
    //     /   \
    //    2     2
    //   / \   / \
    //  3  4  4  3

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2, new TreeNode(3), new TreeNode(4));
    root->right = new TreeNode(2, new TreeNode(4), new TreeNode(3));

    Solution sol;
    bool result = sol.isSymmetric(root);

    if (result)
        cout << "The tree is symmetric." << endl;
    else
        cout << "The tree is not symmetric." << endl;

    return 0;
}
