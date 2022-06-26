class Solution {
public:
    int dp[1001];
    int solve(vector<int>&v, int x){
        if(x==0){
            return 1;
        }
        if(dp[x]!=-1)
            return dp[x];
        dp[x] = 0;
        for(int i=0; i<v.size(); i++){
            if(v[i]<=x){
                dp[x]+=solve(v, x-v[i]);
            }
        }
        return dp[x];
    }
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, target);
    }
};