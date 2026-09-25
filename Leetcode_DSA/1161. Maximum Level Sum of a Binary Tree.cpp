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
    unordered_map<int,int> mp; //level,sum
    void find_level(TreeNode* root,int lcl_level){
        if(!root) return ;
        find_level(root->left,lcl_level+1);
        find_level(root->right,lcl_level+1);
        mp[lcl_level] += root->val; 
    }
    int maxLevelSum(TreeNode* root) {
        find_level(root,1);
        int res =INT_MIN,res_level = 0;
        for(auto& i:mp){
            if(i.second>res){
                res = i.second;
                res_level = i.first;
            }
        }
        return res_level;
    }
};