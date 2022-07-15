class Solution {
public:
    int solve(vector<vector<int>>&grid, int i, int j, int m, int n, vector<vector<int>>&vis){
        if(i>=m or j>=n or j<0 or i<0 or vis[i][j]==1 or grid[i][j]==0)
                return 0;
        vis[i][j] = 1;
        return (grid[i][j]+solve(grid, i+1, j, m, n, vis)+solve(grid, i, j+1, m, n, vis)+solve(grid, i-1,j, m, n, vis) + solve(grid, i, j-1, m ,n, vis));
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        vector<vector<int>>vis(m, vector<int>(n,0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!vis[i][j] and grid[i][j]==1){
                    ans = max(ans, solve(grid, i, j, m, n, vis));
                }
            }
        }
        return ans;
    }
};