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
    bool findPath(TreeNode* node, int target, string& path) {
        if (!node) return false;
        if (node->val == target) return true;

        path.push_back('L');
        if (findPath(node->left, target, path)) return true;
        path.pop_back();

        path.push_back('R');
        if (findPath(node->right, target, path)) return true;
        path.pop_back();
        
        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        string ps, pd; // path to starting node and path to destination node
        findPath(root, startValue, ps);
        findPath(root, destValue, pd);

        int i = 0;
        while (i < ps.size() && i < pd.size() && ps[i] == pd[i]) i++;
        // up is no of ups from starting pt, if no ups then it will be "" 
        // and we are removing the common instruction if they are on same side 
        string up = string(ps.size() - i, 'U'); 
        string down = pd.substr(i); // steps from down to destination, here also removing common instruction till common point and calculating rest of the substring
        string res = up + down;

        return res;
    }
};