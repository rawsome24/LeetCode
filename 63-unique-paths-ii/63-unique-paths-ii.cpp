class Solution {
public:
    int dp[101][101];
    int solve(vector<vector<int>>&v, int m, int n, int i, int j){
        if(i<0 || j<0 || i>=m || j>=n){
            return 0;
        }
        if(v[i][j]==1)
            return dp[i][j] = 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(i==m-1 && j==n-1 && v[i][j]!=1){
            return 1;
        }
        return dp[i][j] = solve(v, m, n, i+1, j) + solve(v, m, n, i, j+1);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        memset(dp, -1, sizeof(dp));
        // int dp[m][n];
        return solve(obstacleGrid, m, n, 0, 0);
    }
};