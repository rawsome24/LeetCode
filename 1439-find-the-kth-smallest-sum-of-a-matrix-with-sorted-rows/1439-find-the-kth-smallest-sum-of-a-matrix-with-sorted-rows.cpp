class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        set<pair<int,vector<int>>>s;
        pair<int,vector<int>>p;
        for(int i=0; i<mat.size(); i++)
        {
            p.first+=mat[i][0];
            p.second.push_back(0);
        }
        s.insert(p);
        if(k==1){
            return p.first;
        }
        
        while(k>1)
        {
            auto it = s.begin();
            pair<int,vector<int>>v = (*it);
            s.erase(it);
            for(int i=0; i<mat.size(); i++)
            {
                if(v.second[i]+1<mat[i].size())
                {
                    v.first+=mat[i][v.second[i]+1] - mat[i][v.second[i]];
                    v.second[i]++;
                    s.insert(v);
                    v.second[i]--;
                    v.first+=mat[i][v.second[i]] - mat[i][v.second[i]+1];
                }
                
            }
            k--;
        }
        
        auto temp = s.begin();
        int ans = (*temp).first;
        return ans;
    }
};