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
    int res = 0;
    pair<int,int> trav(TreeNode* root){
        if(root == NULL) return {0,0};
        
        pair<int,int> left =  trav(root->left);
        pair<int,int> right = trav(root->right);
        
        int sum = right.first + left.first + root->val;
        int count  = left.second + right.second +1;
        int curr_avg = sum/count;
        
        if(curr_avg==root->val) res++;
        
        return {sum,count};
    }
    int averageOfSubtree(TreeNode* root) {
        trav(root);
        return res;
    }
};