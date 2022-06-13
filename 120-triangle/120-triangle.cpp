class Solution {
public:
    int dp[201][201];
    int solve(vector<vector<int>>&v, int i, int j){
        if(i==v.size())
            return 0;
        // else if(j>=v[i].size())
        //     return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int sum1 = solve(v, i+1, j);
        int sum2 = solve(v, i+1, j+1);
        return dp[i][j] = min(sum1, sum2) + v[i][j];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        memset(dp, -1, sizeof(dp));
        return solve(triangle, 0, 0);
    }
};