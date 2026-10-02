/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> levelSum;
    void inorder(TreeNode* root, int level) {   // to find level sum
        if(!root) return;
        if(level == levelSum.size()) levelSum.push_back(0);

        levelSum[level] += root->val;

        inorder(root->left, level + 1);
        inorder(root->right, level + 1);
    }
    void solve(TreeNode* root, int level) {
        if(!root) return;

        int siblingSum = 0;

        if(root->left)  siblingSum += root->left->val;
        if(root->right) siblingSum += root->right->val;

        if(root->left)  root->left->val = levelSum[level + 1] - siblingSum;
        if(root->right) root->right->val = levelSum[level + 1] - siblingSum;

        solve(root->left, level + 1);
        solve(root->right, level + 1);
    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        inorder(root, 0);

        root->val = 0;
        solve(root, 0);
        return root;
    }
};