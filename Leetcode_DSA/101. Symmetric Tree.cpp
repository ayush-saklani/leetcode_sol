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
    bool check(TreeNode* left_sub, TreeNode* right_sub) {
        if (left_sub == NULL && right_sub == NULL) return true;
        else if (left_sub == NULL || right_sub == NULL)    return false;

        if (left_sub->val != right_sub->val)   return false;
        
        bool res = check(left_sub->right, right_sub->left);
        bool res2 = check(left_sub->left, right_sub->right);

        return (res == true && res2 == true);
    }
    bool isSymmetric(TreeNode* root) {
        return check(root->left, root->right);
    }
};