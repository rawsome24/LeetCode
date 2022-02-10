class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        vector<pair<int,int>>p(points.size());
        
        for(int i=0; i<points.size(); i++)
        {
            p[i].first = points[i][0];
            p[i].second = points[i][1];
        }
        
        sort(p.begin(),p.end());
        
        int mn = p[0].second,cnt=1;
        // return mn;
        
        for(int i=1; i<p.size(); i++)
        {
            if(mn<p[i].first)
            {
                cnt++; mn = p[i].second;
            }
            if(mn>p[i].second)
                mn = p[i].second;
        }
        return cnt;
        
    }
};