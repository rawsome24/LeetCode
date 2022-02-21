class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& inter) {
        vector<pair<int,int>>p(inter.size());
        
        for(int i=0; i<inter.size(); i++)
        {
            p[i].first = inter[i][0];
            p[i].second = inter[i][1];
        }
        
        sort(p.begin(),p.end());
        
        int start = 0, cnt=p.size();
        
        for(int i=1; i<p.size(); i++)
        {
            if(p[start].first<=p[i].first && p[i].second<=p[start].second)
                cnt--;
            else if(p[start].first==p[i].first && p[i].second>p[start].second)
                {cnt--; start = i;}
            else start = i;
        }
        return cnt;
    }
};