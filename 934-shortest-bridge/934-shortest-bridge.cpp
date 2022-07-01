class Solution {
public:
    void dfs(vector<vector<int>>&v, int i, int j, vector<pair<int,int>>&res){
        if(i<0 or j<0 or i>=v.size() or j>=v.size() or v[i][j]==0)
            return;
        v[i][j] = 0;
        res.push_back({i, j});
        dfs(v, i+1, j, res);
        dfs(v, i, j+1, res);
        dfs(v, i-1, j, res);
        dfs(v, i, j-1, res);
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        int cnt = 0;
        int ans = INT_MAX;
        vector<pair<int,int>>x;
        vector<pair<int,int>>y;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    cnt++;
                    if(cnt==1)
                        dfs(grid,i, j, x);
                    else if(cnt==2)
                        dfs(grid, i, j, y);
                }
            }
        }
        for(int i=0; i<x.size(); i++){
            for(int j=0; j<y.size(); j++){
                int dist = abs(x[i].first-y[j].first)+abs(x[i].second-y[j].second)-1;
                if(dist<ans)
                    ans = dist;
            }
        }
        return ans;
    }
};