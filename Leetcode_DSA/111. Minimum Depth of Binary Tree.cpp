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
    int res = INT_MAX;
    void find_level(TreeNode* root,int lcl_level){
        if(!root) return ;
        if(root->right == NULL && root->left ==NULL){
            res = min(res,lcl_level);
            return;
        }
        if(root->left){
            find_level(root->left,lcl_level+1);
        }
        if(root->right){
            find_level(root->right,lcl_level+1);
        }
    }
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        find_level(root,0);
        return res+1;
    }
};