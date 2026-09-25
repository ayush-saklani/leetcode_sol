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
// old approach
class Solution {
    int currlevel = -1;
    int val = 0;
public:
    void ldfs(TreeNode*root , int rtlvl){
        if(root->left)  ldfs(root->left,rtlvl+1);
        if(root->right) ldfs(root->right,rtlvl+1);
        if(!root->left && !root->right){
            if(rtlvl>currlevel){
                currlevel=rtlvl;
                val=root->val;
            }
            return;
        }
    }
    int findBottomLeftValue(TreeNode* root) {
        ldfs(root, 0);
        return val;
    }
};
// latest approach
class Solution {
public:
    vector<int> level_val = {};
    int max_level = 0;
    void preorder(TreeNode* root,int level) {
        if(!root) return;
        if(level>max_level){
            max_level = level;
            level_val = {};
        }
        if(level == max_level){
            level_val.push_back(root->val);
        }
        preorder(root->left,level+1);
        preorder(root->right,level+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        preorder(root,0);
        return level_val[0];
    }
};