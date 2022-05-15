class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        vector<long long> presum;
        long long currSum=0;
        for(auto it:nums){
            currSum+=it;
            presum.push_back(currSum);
        }
        int cnt=0;
        for(int i=0; i<nums.size()-1; i++){
            if(presum[i]>=presum[presum.size()-1]-presum[i])
                cnt++;
        }
        return cnt;
    }
};