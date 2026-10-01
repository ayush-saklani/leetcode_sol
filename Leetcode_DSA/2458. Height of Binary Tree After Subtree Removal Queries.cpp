// it tried using unordered_map but it was too slow, so used vector instead
// and also, earlier height_level stored all the reach values, but it was too slow, 
// so now it only stores the best and second best reach values for each level  
class Solution {
public:
    vector<int> height;                     // node -> level
    vector<int> depth;                      // node -> subtree height
    vector<pair<int,int>> height_level;     // level -> {best, second best} reach

    int inorder(TreeNode* root,int curr_depth){
        if(!root) return 0;
        int left = inorder(root->left,curr_depth+1);
        int right = inorder(root->right,curr_depth+1);

        height[root->val] = curr_depth;
        depth[root->val] = max(left,right)+1;

        int reach = curr_depth + depth[root->val] - 1;

        auto& p = height_level[curr_depth];
        if(reach > p.first){
            p.second = p.first;
            p.first = reach;
        }else if(reach > p.second){
            p.second = reach;
        }

        return max(left,right)+1;
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        height.assign(1000000,-1);
        depth.assign(1000000,-1);
        height_level.assign(1000000,{-1,-1});
        
        inorder(root,0);
        vector<int> res;

        for(auto& i:queries){
            int curr_node_height = height[i];
            int my_reach = curr_node_height + depth[i] - 1;
            auto& p = height_level[curr_node_height];

            int temp = (my_reach == p.first) ? p.second : p.first;

            if(temp == -1){
                res.push_back(max(curr_node_height-1,0));
            }else{
                res.push_back(temp);
            }
        }
        return res;
    }
};