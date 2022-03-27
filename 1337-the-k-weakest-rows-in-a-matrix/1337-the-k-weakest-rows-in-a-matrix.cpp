class Solution {
public:
    // struct myCmp{
    //   bool operator()(pair<int,int>&a, pair<int,int>&b)
    //   {return a.second<b.second;}
    // };
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        multimap<int,int>mmp;
        for(int i=0; i<mat.size(); i++)
        {
            int cnt = 0;
            for(int j=0; j<mat[i].size(); j++)
                cnt += mat[i][j];
            mmp.insert({cnt,i});
        }
        // set<pair<int,int>,myCmp()>st(mp.begin(), mp.end());
        vector<int>ans;
        int i=0;
        for(auto it:mmp)
        {
            ans.push_back(it.second); i++; 
            if(i==k)break;
        }
        return ans;
    }
};