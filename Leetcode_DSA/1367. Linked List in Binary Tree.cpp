/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool res = false;
    bool checker(TreeNode* root,ListNode* head) {
        if(!head) return true; // matlab comapring string (LL) has finished and it has matched so far so TRUE
        if(!root) return false;    // if root khatam hai and Link List bachi hai toh iss line mei matching nahi hai 
        if(root->val != head->val) return false;    // no match so false

        // cout<<root->val<<";"<<head->val<<" ";
        return checker(root->left, head->next) || checker(root->right, head->next); // if any match in left or right subtree
    }
    void preorder(TreeNode* root,ListNode* head) {
        if(!root || res) return;
        if(root->val == head->val){
            if(checker(root,head)) res = true;
            // cout<<endl;
        }
        if(root->left)preorder(root->left,head);
        if(root->right)preorder(root->right,head);
    }
    bool isSubPath(ListNode* head,TreeNode* root) {
        preorder(root,head);
        return res;   
    }
};