class Solution {
public:
    int mod = 1e9+7;
    int dp[1001][1001];
    int path[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    long long int solve(vector<vector<int>>&v, int i, int j, int m, int n){
        if(dp[i][j]!=-1)
            return dp[i][j]%mod;
        long long int sum =1;
        for(int k=0; k<4; k++){
            int newi = i+path[k][0];
            int newj = j+path[k][1];
            if(newi<0 or newj<0 or newi>=m or newj>=n or v[newi][newj]<=v[i][j])
                continue;
            sum = (long long int)(sum%mod+solve(v, newi, newj, m, n)%mod);
        }
        return dp[i][j]=sum%mod;
    }
    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size();
        memset(dp, -1, sizeof(dp));
        int n = grid[0].size();
        long long int ans=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                ans += (solve(grid, i, j, m, n))%mod;
            }
        }
        return ans%mod;
    }
};