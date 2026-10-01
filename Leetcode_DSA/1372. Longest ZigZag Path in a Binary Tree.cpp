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
    void check_zigZag(TreeNode* root,int length,bool l_r) { // true = l & false = r 
        if(!root){
            res = max(res,length-1);                    // -1 cuz we are counting edges not nodes
            return ;
        }
        if(l_r){ // true means left se aaya hai 
            check_zigZag(root->right,length+1,!l_r);    // right bhej
            check_zigZag(root->left,1,l_r);             // left bhej with length reset and flag same
        }else{
            check_zigZag(root->left,length+1,!l_r);     // left bhej
            check_zigZag(root->right,1  ,l_r);          // right bhej with length reset and flag same
        }
    }
    int longestZigZag(TreeNode* root) {
        check_zigZag(root,0,true);
        check_zigZag(root,0,false);
        return res;
    }
};