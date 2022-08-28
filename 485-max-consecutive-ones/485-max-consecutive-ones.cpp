class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0, len = 0;
        int j = 0;
        while(j<nums.size()){
            if(nums[j]==1){
                len++;
                ans = max(ans, len);
            }
            else{
                len = 0;
            }
            j++;
        }
        return ans;
    }
};