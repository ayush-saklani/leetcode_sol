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
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> graph;

        queue<TreeNode*> qu;
        qu.push(root);
        while(!qu.empty()){
            auto front = qu.front();
            qu.pop();

            if(front->right) {
                qu.push(front->right);
                graph[front->val].push_back(front->right->val);           
                graph[front->right->val].push_back(front->val);           
            }
            if(front->left) {
                qu.push(front->left);
                graph[front->val].push_back(front->left->val);           
                graph[front->left->val].push_back(front->val);           
            }
        }


        queue<int> q;
        q.push(start);
        unordered_set<int> visited;
        visited.insert(start);
        
        int time = -1;
        while(!q.empty()){
            int size = q.size();
            time++;
            while(size--){  
                int front = q.front();
                q.pop();
                
                for(auto& it : graph[front]){
                    if(!visited.count(it)){
                        q.push(it);
                        visited.insert(it);
                    }
                }
            }
        }
        return time;
    }
};