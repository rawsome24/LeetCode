class Solution {
public:
    // int solve(int m, int n, int i, int j){
    //     if(i>=m or j>=n or i<0 or j<0)
    //         return 0;
    //     int case1 = 1+solve(m, n, i+1, j);
    //     int case2 = 1+solve(m, n, i, j+1);
    //     return (case1+case2);
    // }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n, 0));
        for(int j=0; j<n; j++)
            dp[m-1][j] = 1;
        for(int i=0; i<m; i++)
            dp[i][n-1] = 1;
        for(int i=m-2; i>=0; i--){
            for(int j=n-2; j>=0; j--)
                dp[i][j] = dp[i+1][j]+dp[i][j+1];
        }
        return dp[0][0];
    }
};