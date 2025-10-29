#include <iostream>
using namespace std;

// -------- Binary Tree Node Definition --------
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// -------- Solution Class --------
class Solution {
public:
    bool isValid(TreeNode* root, int val) {
        if (root == NULL)
            return true;
        if (root->val != val)
            return false;
        return isValid(root->left, val) && isValid(root->right, val);
    }

    bool isUnivalTree(TreeNode* root) {
        return isValid(root, root->val);
    }
};

// -------- Helper Function to Build Example Tree --------
TreeNode* buildUnivalTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(1);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(1);
    return root;
}

// -------- MAIN --------
int main() {
    Solution s;
    TreeNode* root = buildUnivalTree();
    cout << boolalpha << s.isUnivalTree(root); // Expected output: true
    return 0;
}
