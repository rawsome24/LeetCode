class Solution {
public:
    vector<int> topKFrequent(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>pq;
        for(auto it:arr)
            mp[it]++;
        for(auto it=mp.begin(); it!=mp.end(); it++)
        {
            pq.push({it->second,it->first});
            if(pq.size()>k)pq.pop();
        }
        vector<int>ans;
        while(pq.empty()==false)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};