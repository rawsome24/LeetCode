class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
       unordered_map<int,int>mp;
        vector<int>ans;
        for(int i=0; i<arr.size(); i++)
            mp[arr[i]]=i;
        
        for(int i=0; i<arr.size(); i++)
        {
            if(mp.find(target-arr[i])!=mp.end() && i!=mp[target-arr[i]])
                {ans = {i,mp[target-arr[i]]}; break;}
        }
        return ans;
    }
};