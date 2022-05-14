class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        set<vector<int>>st;
        for(int i=0; i<nums.size(); i++){
            int j = i+1, k = nums.size()-1;
            while(j<k){
                if(nums[j]+nums[k]==-nums[i]){
                    vector<int>v={nums[i],nums[j],nums[k]};
                    if(st.find(v)==st.end())
                        ans.push_back(v), st.insert(v);
                    j++; k--;
                }
                else if(nums[j]+nums[k]>-nums[i])
                    k--;
                else 
                    j++;
            }
        }
        return ans;
    }
};