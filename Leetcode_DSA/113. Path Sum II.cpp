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
    vector<vector<int>> res;
    void preorder(TreeNode* root,int targetSum,int currsum,vector<int>& curr_vec){
        if(!root) return;
        currsum = currsum + root->val;
        curr_vec.push_back(root->val);
        if(root->right == NULL &&  root->left == NULL){
            if(currsum == targetSum){
                res.push_back(curr_vec);
            }
        }
        preorder(root->left,targetSum,currsum,curr_vec);
        preorder(root->right,targetSum,currsum,curr_vec);
        currsum -= root->val;
        curr_vec.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> curr_vec;
        preorder(root,targetSum,0,curr_vec);
        return res;
    }
};