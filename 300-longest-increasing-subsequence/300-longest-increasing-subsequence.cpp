class Solution {
public:
    int dp[2501][2502];
    int solve(vector<int>&nums, int ind, int prev_ind){
        if(ind>=nums.size())
            return 0;
        if(dp[ind][prev_ind+1]!=-1)
            return dp[ind][prev_ind+1];
        int len = 0+solve(nums, ind+1, prev_ind);
        if(prev_ind==-1 or nums[ind]>nums[prev_ind])
            len = max(len, 1+solve(nums, ind+1, ind));
        return dp[ind][prev_ind+1]=len;
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, -1);
    }
};