class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<int>>&vis, int i, int j, int m, int n){
        if(i<0 or j<0 or i>=m or j>=n or grid[i][j]=='0' or vis[i][j]==1)
            return;
        vis[i][j] = 1;
        dfs(grid, vis, i+1, j, m, n);
        dfs(grid, vis, i, j+1, m, n);
        dfs(grid, vis, i-1, j, m, n);
        dfs(grid, vis, i, j-1, m, n);
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>vis(m, vector<int>(n, 0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!vis[i][j] and grid[i][j]=='1'){
                    cnt++;
                    dfs(grid, vis, i, j, m, n);
                }
            }
        }
        return cnt;
    }
};