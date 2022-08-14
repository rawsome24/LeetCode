class Solution {
public:
    
    
    
    // int solve(vector<int> &s, int last, int i, int n){
    //     if(i==n) return 0;
    //     if(s[i]>last) return max(1+solve(s, s[i], i+1, n), solve(s, last, i+1, n));
    //     return solve(s, last, i+1, n);
    // }
    
    int lengthOfLIS(vector<int>& nums) {
        int dp[nums.size()];
        dp[0] = 1;
        int ans = 1;
        for(int i=0; i<nums.size(); ++i){
            dp[i] = 1;
            for(int j=0; j<i; j++){
                if(nums[j]<nums[i]) dp[i] = max(dp[i], dp[j]+1);
            }
            ans = max(ans, dp[i]);
        }
        return ans;  
    }
};