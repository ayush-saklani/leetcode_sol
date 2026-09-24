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
    vector<int> res;
    void preorder(TreeNode* root,int& currsum){
        if(!root) return;
        currsum = currsum*10 + root->val;
        if(root->right == NULL &&  root->left == NULL){
            res.push_back(currsum);
        }
        preorder(root->left,currsum);
        preorder(root->right,currsum);
        currsum = currsum/10;
    }
    int sumNumbers(TreeNode* root) {
        int temp = 0;
        preorder(root,temp);
        int sum = accumulate(res.begin(), res.end(), 0); // sum of res // shortcut
        return sum;        
    }
};