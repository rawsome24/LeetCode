class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // unordered_map<int,int>mp;
        // for(int i=0; i<nums.size(); i++)
        //     mp[nums[i]]++;
        // for(auto it = mp.begin(); it!=mp.end(); it++)
        //     if(it->second>(nums.size()/2))return it->first;
        // return 0;
        
        int mj = 0, cnt=1;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[mj]==nums[i])
                cnt++;
            else cnt--;
            if(cnt==0){mj = i; cnt=1;};
        }
        return nums[mj];
    }
};