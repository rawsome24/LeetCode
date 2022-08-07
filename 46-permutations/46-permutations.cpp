class Solution {
public:
    void solve(vector<int>&nums, vector<int>temp, vector<vector<int>>&ans, map<int,int>&mp){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(mp.find(nums[i])==mp.end()){
                mp[nums[i]]=1;
                temp.push_back(nums[i]);
                solve(nums, temp, ans, mp);
                mp.erase(nums[i]);
                temp.pop_back();
            }
            
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        map<int,int>mp;
        vector<vector<int>>ans;
        solve(nums, {}, ans, mp);
        return ans;
    }
};