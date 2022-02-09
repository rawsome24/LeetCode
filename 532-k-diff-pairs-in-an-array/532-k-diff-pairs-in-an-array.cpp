class Solution {
public:
    int findPairs(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        for(auto it:arr)
            mp[it]++;
        int cnt=0;
        if(k==0)
        {
            for(auto it:mp)
                if(it.second>1){cnt++;}
            
        }
        else {
            for(auto it:mp)
            {
                if(mp.find(it.first+k)!=mp.end())cnt++;
            }
        }
        
        return cnt;
    }
};