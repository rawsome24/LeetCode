class Solution {
public:
    int dp[101];
    int solve(vector<int>&arr, int n){
       if(n<0)
           return 0;
        if(dp[n]!=-1)
            return dp[n];
        int sum1 = arr[n]+solve(arr,n-2);
        int sum2 = solve(arr, n-1);
        return dp[n] = max(sum1, sum2);
    }
    int rob(vector<int>& arr) {
        memset(dp, -1, sizeof(dp));
        return solve(arr, arr.size()-1);
    }
};