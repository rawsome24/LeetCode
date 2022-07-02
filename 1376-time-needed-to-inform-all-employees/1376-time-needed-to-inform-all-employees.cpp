class Solution {
public:
    void dfs(int n, int id, vector<int>&informTime, vector<int>adj[], int &ans, int time){
        if(adj[id].empty()){
            ans = max(ans, time);
            return;
        }
        for(auto it:adj[id]){
            time+=informTime[it];
            dfs(n, it, informTime, adj, ans, time);
            time-=informTime[it];
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int>adj[n];
        for(int i=0; i<manager.size(); i++){
            if(manager[i]!=-1)
                adj[manager[i]].push_back(i);
        }
        int time = informTime[headID];
        int ans = INT_MIN;
        dfs(n, headID, informTime, adj, ans, time);
        return ans;
    }
};