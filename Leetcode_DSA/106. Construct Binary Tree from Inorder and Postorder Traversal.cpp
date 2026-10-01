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
    unordered_map<int, int> pos;

    TreeNode* construct(int start,int end,vector<int>& inorder, vector<int>& postorder,int& i){
        if(start > end) return NULL;

        TreeNode* node = new TreeNode(postorder[i]);
        i--;

        int it = pos[node->val];

        // right first is important else i counter will lose its way 
        // cuz i mean look at the post and pre order series 
        // postorder (iteration) from back will be in the right half of inorder series iykyk
        // and i will decrease while making the right subtree and then when we make the left subtree i will be at the right position
        
        node->right = construct(it + 1, end, inorder, postorder, i);
        node->left = construct(start, it - 1, inorder, postorder, i);

        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i = 0; i < inorder.size(); i++){
            pos[inorder[i]] = i;
        }
        int i = postorder.size()-1;
        return construct(0,inorder.size()-1,inorder,postorder,i);
    }
};

// inorder =   [9,3,15,20,7]
//     3
// 9      20
//     15     7
// postorder = [9,15,7,20,3]