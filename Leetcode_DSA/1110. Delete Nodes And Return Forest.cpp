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
    vector<TreeNode*> res;
    unordered_map<int,bool> mp;
    void func(TreeNode* root,bool parent_check){
        if(!root) return ;
        
        // if they are parent and are not to be deleted then count it in
        if(!mp[root->val] && parent_check == true){ 
            res.push_back(root);
        }
        // if deleting current node then for right and left make them the parent 
        bool temp = mp[root->val] ? true : false ;
        func(root->left,temp);
        if(root->left && mp[root->left->val]){
            root->left = NULL;
        }
        func(root->right,temp);        
        if(root->right && mp[root->right->val]){
            root->right = NULL;
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(int i =0;i<to_delete.size();i++){
            mp[to_delete[i]] = true;
        }
        func(root,true);
        return res;
    }
};