class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-2; i++){
            int low = i+1, high = nums.size()-1;
            if(i>=1 and nums[i-1]==nums[i])
                continue;
            while(low<high){
                if(nums[i]+nums[low]+nums[high]==0){
                    ans.push_back({nums[i], nums[low], nums[high]});
                    low++, high--;
                    while(low<high and nums[low-1]==nums[low]){
                        low++;
                    }
                    while(low<high and nums[high+1]==nums[high]){
                        high--;
                    }
                }
                else if(nums[i]+nums[low]+nums[high]>0){
                    high--;
                }
                else
                    low++;
            }
        }
        return ans;
    }
};