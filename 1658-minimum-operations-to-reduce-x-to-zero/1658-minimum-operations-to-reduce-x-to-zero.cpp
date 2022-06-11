class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int cnt=0, sum=0;
        for(auto it:nums)
            sum+=it;
        int res = sum-x, ans=0;
        if(sum-x<0)return -1;
        if(res==0)return nums.size();
        sum=0;
        int i=0, j=0;
        while(j<nums.size()){
            sum+=nums[j];
             while(i<nums.size() && sum>res)
                sum-=nums[i++];
            if(sum==res)
                ans = max(ans, j-i+1);
            j++;
        }
        if(!ans)return -1;
        return nums.size()-ans;
    }
};