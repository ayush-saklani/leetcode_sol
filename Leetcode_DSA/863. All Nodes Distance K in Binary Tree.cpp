/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int, vector<int>> graph; // node,neibour
        queue<TreeNode*> q1;
        q1.push(root);
        while (!q1.empty()) { /*First BFS to get a track of parent nodes*/
            TreeNode* front = q1.front();
            q1.pop();
            if (front->left) {
                graph[front->val].push_back(front->left->val);
                graph[front->left->val].push_back(front->val);
                q1.push(front->left);
            }
            if (front->right) {
                graph[front->val].push_back(front->right->val);
                graph[front->right->val].push_back(front->val);
                q1.push(front->right);
            }
        }
        // done till here check the whole second dfs again (i am making a graph out of tree first)
        unordered_map<int, bool> visited;
        queue<int> q;
        q.push(target->val);
        visited[target->val] = true;
        int curr_level = 0;
        while (!q.empty()) { /*Second BFS to go upto K level from target node and using our hashtable info*/
            int size = q.size();
            if (curr_level++ == k) break;
            for (int i = 0; i < size; i++) {
                int front = q.front();
                q.pop();
                for(auto it:graph[front]){
                    if(!visited[it]){
                        q.push(it);
                        visited[it] = true;
                    }
                }
            }
        }
        vector<int> result;
        while (!q.empty()) {
            int front = q.front();
            q.pop();
            result.push_back(front);
        }
        return result;
    }
};