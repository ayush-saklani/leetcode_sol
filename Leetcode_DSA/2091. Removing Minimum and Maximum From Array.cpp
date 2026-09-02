class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int mini_idx = -1;
        int maxi_idx = -1;
        for(int i=0;i<nums.size();i++){
            mini = min(mini,nums[i]);
            maxi = max(maxi,nums[i]);
        }

        for(int i=0;i<nums.size();i++){
            if(nums[i] == mini && mini_idx == -1){
                mini_idx = i;
            }
            if(nums[i] == maxi && maxi_idx == -1){
                maxi_idx = i;
            }
        }
        int n = nums.size();
        int res = INT_MAX;

        int l = min(mini_idx,maxi_idx);
        int r = max(mini_idx,maxi_idx);
        
        //right ke and left ke, right wale ke left wale, left wale ke right wale 
        res = min({ ((l+1)+(n-r)) , (r+1) , (n-l) });
        return res;
    }
};