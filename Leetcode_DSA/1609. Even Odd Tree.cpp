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
    unordered_map<int,vector<int>> mp;
    int max_level = 0;
    bool res = true;
    void preorder(TreeNode* root,int level) {
        if(!root) return;
        max_level = max(max_level,level);
        preorder(root->left,level+1);
        mp[level].push_back(root->val);
        preorder(root->right,level+1);
        if(level%2 == 0 && root->val%2 == 0) res = false;
        else if(level%2 != 0 && root->val%2 != 0) res = false;

    }
    bool isEvenOddTree(TreeNode* root) {
        preorder(root,0);
        if(!res) return res;
        for(int i=0;i<=max_level;i++){
            for(int it=1;it<mp[i].size();it++){
                if(i%2 != 0 && mp[i][it] >= mp[i][it-1]){
                    return false;
                }
                else if(i%2 == 0 && mp[i][it] <= mp[i][it-1]){
                    return false;
                }
            }
        }
        return true;
    }
};