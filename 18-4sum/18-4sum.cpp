class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        set<vector<int>>st;
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                int low = j+1, high = nums.size()-1;
                while(low<high){
                    if((long long)nums[i]+nums[j]+nums[low]+nums[high]==(long long)target){
                        vector<int>v = {nums[i], nums[j], nums[low], nums[high]};
                        if(st.find(v)==st.end())
                            ans.push_back(v);
                        st.insert({nums[i], nums[j], nums[low], nums[high]});
                        low++; high--;
                    }
                    else if((long long)nums[i]+nums[j]+nums[low]+nums[high]>(long long)target){
                        high --;
                    }
                    else
                        low++;
                }
            }
        }
        return ans;
    }
};