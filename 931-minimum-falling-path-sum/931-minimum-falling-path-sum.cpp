class Solution {
public:
    int dp[101][101];
    int solve(vector<vector<int>>&v, int i, int j, int n){
        if(i>=n || j>=n)
            return 0;
        
        if(i==n-1)
            return v[i][j];
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int sum1 = INT_MAX, sum2 = INT_MAX, sum3 = INT_MAX;
        
        if(j<n && i+1<n){
            sum1 = v[i][j]+solve(v, i+1, j, n);
        }
        if(j+1<n && i+1<n){
            sum2 = v[i][j]+solve(v, i+1, j+1, n);
        }
        if(j-1>=0 && i+1<n){
            sum3 = v[i][j]+solve(v, i+1, j-1, n);
        }
        return dp[i][j] = min(sum1, min(sum2, sum3));
        
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT_MAX;
        int n = matrix.size();
        memset(dp, -1, sizeof(dp));
        for(int i=0; i<n; i++){
            ans = min(ans, solve(matrix, 0, i, matrix.size()));
        }
        return ans;
    }
};