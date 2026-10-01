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
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        int depth = 0;
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            int temp_max = INT_MIN;
            while(size--){
                auto front = q.front();
                q.pop();
                temp_max = max(temp_max,front->val);
                if(front->right) q.push(front->right);
                if(front->left) q.push(front->left);
            }
            res.push_back(temp_max);
        }
        return res;
    }
};