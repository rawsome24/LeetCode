class Solution {
public:
    void fun(int ind,vector<int> temp,vector<int>& nums,set<vector<int>> &st,vector<vector<int>> &ans)
    {
        if(ind == nums.size())
        {
            if(st.find(temp) == st.end())
            {
                st.insert(temp);
                ans.push_back(temp);
            }
            return;
        }
        fun(ind+1,temp,nums,st,ans);
        temp.push_back(nums[ind]);
        fun(ind+1,temp,nums,st,ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        set<vector<int>> st;
        fun(0,{},nums,st,ans);
        return ans;
    }
};