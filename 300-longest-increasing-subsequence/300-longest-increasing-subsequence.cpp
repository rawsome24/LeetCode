class Solution {
public:
    int dp[2501][2502];
    int solve(vector<int>&nums, int j, int ele){
        if(j>=nums.size())
            return 0;
        int ans=0;
        if(dp[j][ele+1]!=-1)
            return dp[j][ele+1];
        if(ele==-1 or nums[j]>nums[ele]){
            int case1 = 1+solve(nums, j+1, j);
            int case2 = 0+solve(nums, j+1, ele);
            ans = max(case1, case2);
        }
        else
            ans = 0+solve(nums, j+1, ele);
        return dp[j][ele+1]=ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, -1);
    }
};