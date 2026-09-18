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
    bool res = false;
    int currsum = 0;
    void preorder(TreeNode* root, int targetSum){
        if(!root) return;
        currsum = currsum + root->val;
        if(root->right == NULL &&  root->left == NULL){
            if(currsum == targetSum){
                res = true;
            }
        }
        preorder(root->left,targetSum);
        preorder(root->right,targetSum);
        currsum -= root->val;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        preorder(root,targetSum);
        return res;
    }
};