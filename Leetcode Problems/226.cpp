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
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL)
            return NULL;

        TreeNode* leftNode = invertTree(root->left);
        TreeNode* rightNode = invertTree(root->right);

        root->left = rightNode;
        root->right = leftNode;

        return root;
    }
};

// -------- Helper Functions --------
TreeNode* buildTree() {
    // Example tree:
    //        4
    //       / \
    //      2   7
    //     / \ / \
    //    1  3 6  9
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    return root;
}

void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

// -------- MAIN --------
int main() {
    Solution s;
    TreeNode* root = buildTree();

    cout << "Original Tree (Inorder): ";
    printInorder(root);
    cout << endl;

    root = s.invertTree(root);

    cout << "Inverted Tree (Inorder): ";
    printInorder(root);
    cout << endl;

    return 0;
}
