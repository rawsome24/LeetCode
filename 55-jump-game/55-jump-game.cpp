class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i=0;
        int step = nums[0];
        int maxR = nums[0];
        if(nums[0]==0 && nums.size()>1)return false;
        while(i<nums.size()){
            if(i==nums.size()-1)
                return true;
            maxR = max(maxR, nums[i]+i);
            step--;
            if(step==0){
                if(i>=maxR)
                    return false;
                step = maxR - i;
            }
            i++;
        }
        return true;
    }
};