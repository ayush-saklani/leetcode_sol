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
// best approach
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()){
            int size = q.size();
            int temp = -1;
            while(size){
                auto front = q.front();
                if(front->left)q.push(front->left);
                if(front->right)q.push(front->right);
                
                if(level%2 == 0 && front->val%2 == 0) return false;
                else if(level%2 != 0 && front->val%2 != 0) return false;

                if(temp != -1){
                    if(level%2==0 && front->val<=temp) return false;
                    else if(level%2!=0 && front->val>=temp) return false;
                }
                temp = front->val;
                q.pop();
                size--;
            }
            level++;
        }
        return true;
    }
};
// worst approach i thought (brute force)
class Solution {
public:
    unordered_map<int,vector<int>> mp;
    int max_level = 0;
    bool res = true;
    void preorder(TreeNode* root,int level) {
        if(!root) return;
        max_level = max(max_level,level);
        preorder(root->left,level+1);
        mp[level].push_back(root->val);
        preorder(root->right,level+1);
        if(level%2 == 0 && root->val%2 == 0) res = false;
        else if(level%2 != 0 && root->val%2 != 0) res = false;

    }
    bool isEvenOddTree(TreeNode* root) {
        preorder(root,0);
        if(!res) return res;
        for(int i=0;i<=max_level;i++){
            for(int it=1;it<mp[i].size();it++){
                if(i%2 != 0 && mp[i][it] >= mp[i][it-1]){
                    return false;
                }
                else if(i%2 == 0 && mp[i][it] <= mp[i][it-1]){
                    return false;
                }
            }
        }
        return true;
    }
};