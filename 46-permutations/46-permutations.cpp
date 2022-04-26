class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>v;
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        do{
            for(auto it:nums)
                v.push_back(it);
            ans.push_back(v);
            v.clear();
        }while(next_permutation(nums.begin(),nums.end()));
        return ans;
    }
};