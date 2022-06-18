class Solution {
public:
    int dp[5001][2];
    int solve(vector<int>&v, int i, bool f){
        if(i>=v.size())
            return 0;
        if(dp[i][f]!=-1)
            return dp[i][f];
        if(!f){
            int x = solve(v, i+1, true)-v[i];
            int y = solve(v, i+1, false);
            return dp[i][f] = max(x,y);
        }else{
            int x = solve(v, i+2, false)+v[i];
            int y = solve(v, i+1, true);
            return dp[i][f] = max(x,y);
        }
    }
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return solve(prices, 0, false);
    }
};