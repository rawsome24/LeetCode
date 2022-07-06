class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,vector<int>>>pq;
        double dis = sqrt(points[0][0]*points[0][0]+points[0][1]*points[0][1]);
        // cout<<dis<<endl;
        pq.push({dis, points[0]});
        for(int i=1; i<points.size(); i++){
            double origindis = sqrt((points[i][0]*points[i][0])+(points[i][1]*points[i][1]));
            // cout<<origindis<<endl;
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