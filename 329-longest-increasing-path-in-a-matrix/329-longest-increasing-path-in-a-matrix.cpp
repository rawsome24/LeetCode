class Solution {
public:
    int path[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    int dp[201][201];
    int solve(vector<vector<int>>&v, int m, int n, int i, int j){
        if(dp[i][j]!=-1)
            return dp[i][j];
        int maxp = 1;
        for(int k=0; k<4; k++){
            int newi = i+path[k][0];
            int newj = j+path[k][1];
            if(newi<0 or newj<0 or newi>=m or newj>=n or v[newi][newj]<=v[i][j])
                continue;
            maxp =  max(1+solve(v, m, n, newi, newj), maxp);
        }
        return dp[i][j] = maxp;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        memset(dp, -1, sizeof(dp));
        int ans = 1;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                ans = max(solve(matrix, m, n, i, j), ans);
            }
        }
        return ans;
    }
};