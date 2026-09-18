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
    void preorder(TreeNode* root,int maxi,int mini){
        if(!root) return;
        maxi = max(maxi,root->val);
        mini = min(mini,root->val);
        res = max(res,abs(maxi-mini));

        preorder(root->left,maxi,mini);
        preorder(root->right,maxi,mini);
    }
    int maxAncestorDiff(TreeNode* root) {
        preorder(root,root->val,root->val);
        return res;
    }
};