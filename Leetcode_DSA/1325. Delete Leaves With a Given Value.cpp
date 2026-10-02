/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root, int target) {
        if (!root) return;

        inorder(root->left, target);
        inorder(root->right, target);

        if (root->right != NULL && root->right->right == NULL &&
            root->right->left == NULL && root->right->val == target) {
            root->right = NULL;
        }
        if (root->left && root->left->right == NULL &&
            root->left->left == NULL && root->left->val == target) {
            root->left = NULL;
        }
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        inorder(root, target);
        if (root->right == NULL && root->left == NULL && root->val == target) return {};
        return root;
    }
};