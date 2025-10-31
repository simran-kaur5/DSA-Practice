#include <bits/stdc++.h>
using namespace std;

// ---------------- Definition for a binary tree node ----------------
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// ---------------- Solution Class ----------------
class Solution {
public:
    string dup(TreeNode* root, unordered_map<string, int> &m, vector<TreeNode*> &ans) {
        if (root == nullptr) return "#";

        string left_serial = dup(root->left, m, ans);
        string right_serial = dup(root->right, m, ans);

        string serial = to_string(root->val) + "," + left_serial + "," + right_serial;
        m[serial]++;

        if (m[serial] == 2) {
            ans.push_back(root);
        }
        return serial;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> m;
        vector<TreeNode*> ans;
        dup(root, m, ans);
        return ans;
    }
};

// ---------------- Helper Functions for Testing ----------------
TreeNode* newNode(int val) {
    return new TreeNode(val);
}

// Example tree:
//      1
//     / \
//    2   3
//   /   / \
//  4   2   4
//     /
//    4
TreeNode* buildTestTree() {
    TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(2);
    root->right->left->left = newNode(4);
    root->right->right = newNode(4);
    return root;
}

// Print subtree in preorder for visualization
void printPreorder(TreeNode* root) {
    if (!root) {
        cout << "# ";
        return;
    }
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    TreeNode* root = buildTestTree();
    Solution sol;
    vector<TreeNode*> duplicates = sol.findDuplicateSubtrees(root);

    cout << "Duplicate Subtrees (Preorder):\n";
    for (auto node : duplicates) {
        printPreorder(node);
        cout << "\n";
    }
    return 0;
}
