class Solution {
public:
    
    bool possible(int a, int b, vector<vector<int>>& bo){
        if(bo[a][2] >= sqrt(pow(bo[a][0] - bo[b][0], 2) + pow(bo[a][1] - bo[b][1], 2)))
            return true;
        return false;
    }
    
    int detonate(int k, vector<int> &vis, vector<vector<int>>& bombs){
        vis[k] = 1;
        int cnt = 1;
        for(int i=0; i<bombs.size(); i++){
            if(!vis[i] && possible(k, i, bombs))
                cnt += detonate(i, vis, bombs);
        }
        return cnt;
    }
    
    int maximumDetonation(vector<vector<int>>& bombs) {
        int ans = 0;
        for(int i=0; i<bombs.size(); i++){
            vector<int> vis(bombs.size(), 0);
            ans = max(ans, detonate(i, vis, bombs));
        }
        return ans;
    }
};