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
    void preorder(TreeNode* root,vector<int>& leafs){
        if(!root) return;
        preorder(root->left,leafs);
        if(root->right == NULL && root->left ==NULL){
            leafs.push_back(root->val);
        }
        preorder(root->right,leafs);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf_1,leaf_2;
        preorder(root1,leaf_1);
        preorder(root2,leaf_2);
        if(leaf_1.size() != leaf_2.size()){
            return false;
        }
        for(int i =0;i<leaf_1.size();i++){
            if(leaf_1 != leaf_2){
                return false;
            }
        }
        return true;   
    }
};