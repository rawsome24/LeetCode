class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int mn = INT_MAX, mx = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            int j=i+1, k = nums.size()-1;
            while(j<k){
                if(nums[i]+nums[j]+nums[k]<target){
                    mx = max(mx, nums[i]+nums[j]+nums[k]);
                    j++;
                }
                else if(nums[i]+nums[j]+nums[k]>target){
                    mn = min(mn, nums[i]+nums[j]+nums[k]);
                    k--;
                }
                else{
                    return target;
                }
            }
        }
        if(mx!=INT_MIN && mn!=INT_MAX && abs(target-mx)<abs(target-mn))return mx;
        else if(mx==INT_MIN && mn!=INT_MAX)return mn;
        else if(mn==INT_MAX && mx!=INT_MIN)return mx;
        else return mn;
    }
};