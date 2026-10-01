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
    bool check(TreeNode* p, TreeNode* q){
        bool res,res2;
        if(p==NULL && q==NULL) return true;
        else if(p==NULL || q==NULL) return false;
        
        if(p->val != q->val) return false;
        else if(p->val == q->val){
            res = (check(p->right, q->left) && check(p->left, q->right));
            res2 = (check(p->right, q->right) && check(p->left, q->left));
        }
        return (res || res2);
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        bool res = check(root1,root2);
        return res;
    }
};