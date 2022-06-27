class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        vector<int>indegree(numCourses,0);
        vector<int>adj[numCourses];
        for(int i=0; i<pre.size(); i++){
            adj[pre[i][1]].push_back(pre[i][0]);
            indegree[pre[i][0]]++;
        }
        queue<int>q;
        for(int i=0; i<indegree.size(); i++){
            if(indegree[i]==0)
                q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }
        for(int i=0; i<indegree.size(); i++){
            if(indegree[i]!=0)
                return false;
        }
        return true;
    }
};