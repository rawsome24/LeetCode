class Solution {
public:
    int dp[201][201];
    int solve(vector<vector<int>>&grid, int i, int j, int n, int m){
        if(i<0 || j<0)
            return INT_MAX;
        else if(i==0 && j==0)
            return grid[i][j];
        else if(dp[i][j]!=-1)
            return dp[i][j];
        return dp[i][j] = grid[i][j]+min(solve(grid, i-1,j, n,m), solve(grid, i,j-1, n, m));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        memset(dp, -1, sizeof(dp));
       return solve(grid,n-1, m-1, n, m);
        
    }
};