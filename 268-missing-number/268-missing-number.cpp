class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum1 = (n*(n+1))/2;
        int sum2 = 0;
        for(auto it:nums){
            sum2+=it;
        }
        return sum1-sum2;
    }
};