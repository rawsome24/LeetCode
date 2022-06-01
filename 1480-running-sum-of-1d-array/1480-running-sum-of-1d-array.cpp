class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int>pre(nums.size());
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            pre[i] = sum;
        }
        return pre;
    }
};