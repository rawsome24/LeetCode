class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        if(nums.size()==1) return res;
        int maxEnding = nums[0];
        for(int i=1; i<nums.size(); i++)
        {
            maxEnding = max(maxEnding+nums[i], nums[i]);
            res = max(res, maxEnding);
        }
        return res;
    }
};