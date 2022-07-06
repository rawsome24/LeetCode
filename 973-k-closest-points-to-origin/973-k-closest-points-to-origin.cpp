class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,vector<int>>>pq;
        for(int i=0; i<points.size(); i++){
            double origindis = sqrt((points[i][0]*points[i][0])+(points[i][1]*points[i][1]));
            pq.push({origindis, points[i]});
            if(pq.size()>k)
                pq.pop();
        }
        vector<vector<int>>ans;
        while(!pq.empty()){
            vector<int>temp = pq.top().second;
            pq.pop();
            ans.push_back(temp);
        }
        return ans;
    }
};