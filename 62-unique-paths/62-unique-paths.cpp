class Solution {
public:
    int dp[101][101];
    int solve(vector<vector<int>>&grid, int m, int n){
        for(int k=0; k<m; k++){
            dp[k][n-1] = 1;
        }
        for(int l=0; l<n; l++){
            dp[m-1][l] = 1;
        }
        
        for(int i=m-2; i>=0; i--){
            for(int j=n-2; j>=0; j--){
                dp[i][j] = dp[i+1][j]+dp[i][j+1];
            }
        }
        return dp[0][0];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>grid(m, vector(n, 0));
        memset(dp,0, sizeof(dp));
        return solve(grid, m, n);
    }
};