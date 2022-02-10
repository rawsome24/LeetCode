class Solution {
public:
    struct myCmp{
        bool operator()(pair<int,int>&a, pair<int,int>&b){
            return a.second<b.second;
        }
    };
    
    
    int eraseOverlapIntervals(vector<vector<int>>& inter) {
        
        vector<pair<int,int>>p(inter.size());
        
        for(int i=0; i<inter.size(); i++)
        {
            p[i].first = inter[i][0];
            p[i].second = inter[i][1];
        }
        
        sort(p.begin(),p.end(),myCmp());
        
        int cnt = 0,start=0;
        
        for(int i=1; i<p.size(); i++)
        {
            if(p[start].second>p[i].first)
                {cnt++;}
            else if(p[start].second<=p[i].first) start = i;
        }
        
        return cnt;
    }
};