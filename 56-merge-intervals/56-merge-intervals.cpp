class Solution {
public:
    
    struct myCmp{
      
        bool operator()(pair<int,int>&a, pair<int,int>&b)
            {return a.first<b.first;}
        
    };
    
    vector<vector<int>> merge(vector<vector<int>>& iv) {
        
        vector<pair<int,int>>p(iv.size());
        
        for(int i=0; i<iv.size(); i++)
        {
            p[i].first = iv[i][0];
            p[i].second = iv[i][1];
        }
        
        sort(p.begin(),p.end(),myCmp());
        
        vector<vector<int>>ans;
        
        vector<int> v(2);
        v[0] = p[0].first;
        v[1] = p[0].second;
        
        int start = 0;
        
        for(int i=1; i<p.size(); i++)
        {
            if(v[1]>=p[i].first)
                v[1] = max(v[1], p[i].second);
            else
            {
                ans.push_back(v);
                v[0] = p[i].first;
                v[1] = p[i].second;
            }
        }
        ans.push_back(v);
        return ans;
        
        
    }
};