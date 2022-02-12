class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0, j=0, cnt0=0;
        int mx = 0;
        while(j<nums.size())
        {
            if(nums[j]==0)
                cnt0++;
            
            if(cnt0<=k)
            {
                mx = max(mx, j-i+1);
                j++;
            }
            
            else if(cnt0>k)
            {
                while(cnt0>k)
                {
                    if(nums[i]==0)cnt0--;
                    i++;
                }
                j++;
            }
        }
        return mx;
    }
};