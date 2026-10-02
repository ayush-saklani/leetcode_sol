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
    // vector<vector<int>> level_wise;  // vector is faster than unordered_map here cuz we are using level as index and it is continuous
    unordered_map<int,vector<int>> level_wise;
    void inorder(TreeNode* root, int level) {
        if(!root) return;
        
        // if (level == level_wise.size()) level_wise.push_back({});
        level_wise[level].push_back(root->val);

        inorder(root->left, level + 1);
        inorder(root->right, level + 1);
    }
    void inorder2(TreeNode* root, int level) {
        if(!root) return;
        if(level%2!=0){
            int size = level_wise[level].size();
            root->val = level_wise[level][size-1];
            level_wise[level].pop_back();
        }
        inorder2(root->left, level + 1);
        inorder2(root->right, level + 1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        inorder(root,0);
        inorder2(root,0);
        return root;
    }
};