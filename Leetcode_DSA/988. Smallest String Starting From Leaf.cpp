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
    string res = "{}";
    void preorder(TreeNode* root,string str) {
        if(!root) return;
        str.push_back((root->val+'a'));
        if(!root->left && !root->right) {
            string temp = str;
            reverse(temp.begin(),temp.end());
            if(temp<res) res = temp;
            return ;
        }
        if(root->left)preorder(root->left,str);
        if(root->right)preorder(root->right,str);
    }
    string smallestFromLeaf(TreeNode* root) {
        preorder(root,"");
        return res;
    }
};