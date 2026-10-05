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
    int res = 0;
    int inorder(TreeNode* root){
        if(root == NULL) return 0;
        int left = inorder(root->left);
        int right = inorder(root->right);
        res += abs(left)+abs(right);
        return root->val-1+left+right;
    }
    int distributeCoins(TreeNode* root) {
        inorder(root);
        return res;
    }
};