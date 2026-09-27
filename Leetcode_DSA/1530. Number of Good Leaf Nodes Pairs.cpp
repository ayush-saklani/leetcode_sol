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
    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*,vector<TreeNode*>> mp;
        unordered_map<TreeNode*,bool> leaves;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            if(front->left == NULL && front->right == NULL){
                leaves[front] = true;
            }
            if(front->left) {
                mp[front].push_back(front->left);
                mp[front->left].push_back(front);
                q.push(front->left);
            }
            if(front->right) {
                mp[front].push_back(front->right);
                mp[front->right].push_back(front);
                q.push(front->right);
            }
        }
        int res = 0;
        
        for(auto& i:leaves){
            queue<TreeNode*> q;
            q.push(i.first);
            unordered_map<TreeNode*,bool> visited; 
            visited[i.first] = true;
            int reach = distance;
            while(reach>0 && !q.empty()){
                int size = q.size();
                while(size--){
                    auto front = q.front();
                    q.pop();
                    // cout<<front->val<<" ";
                    for(auto it:mp[front]){
                        if(!visited[it]){
                            if(leaves.find(it) != leaves.end()) {
                                res++;
                            }
                            q.push(it);
                            visited[it] = true;
                        }
                    }
                }
                reach--;
            }
                // cout<<endl;
        }
        return res/2;
    }
};