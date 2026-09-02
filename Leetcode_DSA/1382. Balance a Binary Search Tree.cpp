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
    vector<int> val;
    void inorder(TreeNode* root){
        if(root == NULL) return;
        inorder(root->left);
        val.push_back(root->val);
        inorder(root->right);
    }
    TreeNode* buildTree(int l,int r) {
        if(l > r) return nullptr;
        int mid = (l+r)/2;
        TreeNode* node = new TreeNode(val[mid]);
        node->left = buildTree(l,mid-1);
        node->right = buildTree(mid+1,r);
        return node; 
    }
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        int n = val.size();
        return buildTree(0,n-1);
    }
};