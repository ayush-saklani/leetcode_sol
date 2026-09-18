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
    void preorder(TreeNode* root,int targetlevel,int level,int val){
        if(!root) return;
        preorder(root->left,targetlevel,level+1,val);
        if(level == targetlevel-1){
            TreeNode *rightnode = new TreeNode(val);
            rightnode->right = root->right;
            root->right = rightnode;

            TreeNode *leftnode = new TreeNode(val);
            leftnode->left = root->left;
            root->left = leftnode;
        }
        preorder(root->right,targetlevel,level+1,val);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode *node = new TreeNode(val);
            node->left = root;
            return node;    
        }
        preorder(root,depth,1,val);
        return root;        
    }
};