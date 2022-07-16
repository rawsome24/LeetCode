class Solution {
    int dp[51][51][52];
    int mod = 1e9+7;
public:
    int solve(int m, int n, int maxMove, int i, int j){
        if(i>=m or i<0 or j>=n or j<0)
            return 1;
        if(maxMove==0)
            return 0;
        if(dp[i][j][maxMove]!=-1)
            return dp[i][j][maxMove]%mod;
        int temp = 0;
        temp = (temp%mod+solve(m, n, maxMove-1, i+1, j))%mod;
        temp = (temp%mod+solve(m, n, maxMove-1, i, j+1))%mod;
        temp = (temp%mod+solve(m, n, maxMove-1, i-1, j))%mod;
        temp = (temp%mod+solve(m, n, maxMove-1, i, j-1))%mod;
        return dp[i][j][maxMove] = (temp%mod);
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof(dp));
        return solve(m, n, maxMove, startRow, startColumn)%mod;
    }
};