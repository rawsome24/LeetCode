class Solution {
public:
    int dp[100002];
    bool solve(vector<int>&nums, int i){
        if(i>=nums.size())
            return true;
        if(dp[i]!=-1)
            return dp[i];
        if(i+1<nums.size() and (nums[i]==nums[i+1])){
            if(solve(nums, i+2))
                return true;
            if(i+2<nums.size() and nums[i]==nums[i+2])
                if(solve(nums, i+3)) return true;
        }
        if(i+2<nums.size() and nums[i]==nums[i+1]-1 and nums[i+1]==nums[i+2]-1)
            if(solve(nums, i+3))
                return true;
        return dp[i] = false;
    }
    bool validPartition(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0);
    }
};