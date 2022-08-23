class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int val = nums[0];
        int cnt = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==val)
                cnt++;
            else
                cnt--;
            if(cnt==0){
                val = nums[i];
                cnt = 1;
            }
        }
        return val;
    }
};