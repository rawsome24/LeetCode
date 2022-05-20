class Solution {
public:
    int dp[101];
    int solve(vector<int>&arr, int n, int end){
        if(n>end)return 0;
        else if(dp[n]!=-1)return dp[n];
        int sum1 = arr[n]+solve(arr, n+2, end);
        int sum2 = solve(arr, n+1, end);
        return dp[n] = max(sum1, sum2);
    }
    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        if(nums.size()==1)return nums[0];
        else if(nums.size()==2)return *max_element(nums.begin(), nums.end());
        int maxa = 0;
        maxa = max(maxa,solve(nums, 0, nums.size()-2));
        memset(dp, -1, sizeof(dp));
        maxa = max(maxa, solve(nums, 1, nums.size()-1));
        return maxa;
    }
};