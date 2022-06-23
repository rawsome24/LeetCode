class Solution {
public:
    void dfs(vector<vector<int>>&graph, vector<vector<int>>&ans, int node, int n, vector<int>v){
        if(node==n){
            ans.push_back(v);
            return;
        }
        for(auto it:graph[node]){
            v.push_back(it);
            dfs(graph, ans, it, n, v);
            v.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        vector<int>v;
        v.push_back(0);
        dfs(graph, ans, 0, graph.size()-1, v);
        return ans;
    }
};