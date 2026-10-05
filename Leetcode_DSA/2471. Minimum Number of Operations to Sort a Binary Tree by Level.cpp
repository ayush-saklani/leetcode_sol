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
    vector<vector<int>> level_wise;
    void inorder(TreeNode* root, int level) {
        if(!root) return;
        
        if (level == level_wise.size()) level_wise.push_back({});
        level_wise[level].push_back(root->val);
        
        inorder(root->left, level + 1);
        inorder(root->right, level + 1);
    }
    // this sorting logic is copied from internet and I don't know how it works
    // it has a very complex way to sort as we update the index of the elements in the array and swap them to their correct position
    // but it is quite hard to understand
    int operation(vector<int>& arr){ 
        map<int, int> reverseIndex;
        for(int i = 0; i < arr.size(); ++i) reverseIndex[arr[i]] = i;
        int ans = 0;
        int idx = 0;
        for(auto& [k,v] : reverseIndex){
            if(v == idx) { 
                idx++; 
                continue; 
            }
            reverseIndex[arr[idx]] = v;
            swap(arr[idx], arr[v]);
            ans++; 
            idx++;
        }
        return ans;
    }
    
    int minimumOperations(TreeNode* root) {
        int res = 0;
        inorder(root,0);
        for(auto& i:level_wise){
            res += operation(i);
            // for(auto it:i) cout<<it<<" ";
            // cout<<endl;
        }
        return res;
    }
};