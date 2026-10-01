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
    vector<int> path_node;
    void inorder (TreeNode* root) {
        if(!root) return ;
        path_node[root->val]++;
        if(root->right == NULL && root-> left == NULL){
            int odd = 0;
            for(int i=0;i<10;i++){
                if(path_node[i] % 2 !=0){
                    odd++;
                    if(odd>1) break;
                }
            }
            if(odd<2) res++;
        }
        inorder(root->left);
        inorder(root->right);

        path_node[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        path_node.assign(10,0);
        inorder(root);
        return res;
    }
};