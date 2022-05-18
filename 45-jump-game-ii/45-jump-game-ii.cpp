class Solution {
public:
    int jump(vector<int>& nums) {
        int jump=1, step = nums[0], maxR = nums[0];
        int i = 1;
        if(nums.size()==1)return 0;
        while(i<nums.size())
        {
            if(i==nums.size()-1)
                return jump;
            maxR = max(maxR, nums[i]+i);
            step--;
            if(step==0)
            {
                if(i>=maxR)
                    return -1;
                jump++;
                step = maxR - i;
            }
            i++;
        }
        return jump;
    }
};