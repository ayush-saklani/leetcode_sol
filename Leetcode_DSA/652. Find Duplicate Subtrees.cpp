/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    map<pair<int,int>, vector<TreeNode*>> mp;
    vector<TreeNode*> res;
    unordered_set<TreeNode*> res_mp;
    bool check(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        if (p->val != q->val) return false;
        return check(p->left, q->left) && check(p->right, q->right);  // stops at first mismatch
    }
    int inorder(TreeNode* root) {
        if(!root) return 0;
        int l = inorder(root->left);
        int r = inorder(root->right);
        int size = l+r+1;

        pair<int,int> key = {root->val,size};
        if(mp.find(key) != mp.end()){
            bool found = false;
            for(auto& it:mp[key]){
                if(check(root,it)){
                    found = true;           
                    if(res_mp.find(it) == res_mp.end()) {
                        res.push_back(root);
                        res_mp.insert(it);
                    }
                    break;
                }
            }
            if(!found) {
                mp[key].push_back(root);
            }
        }
        else {
            mp[key].push_back(root);
        }
        return size;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        inorder(root);
        return res;
    }
};