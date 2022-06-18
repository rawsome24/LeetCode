class Solution {
public:
    int dp[100001][2];
    int solve(vector<int>&v, int fee, int i, int buy){
        if(i>=v.size())
            return 0;
        
        if(dp[i][buy]!=-1)
            return dp[i][buy];
        
        if(buy){
            int x = solve(v, fee, i+1, 0)+v[i]-fee;
            int y = solve(v, fee, i+1,  1);
            return dp[i][buy] = max(x,y);
        }
        else{
            int x = solve(v, fee, i+1, 1)-v[i];
            int y = solve(v, fee, i+1, 0);
            return dp[i][buy] = max(x, y);
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        memset(dp, -1, sizeof(dp));
        return solve(prices, fee, 0, 0);
    }
};

