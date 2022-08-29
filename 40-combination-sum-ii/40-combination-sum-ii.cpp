class Solution {
public:
    void solve(vector<int>&arr, int target, vector<vector<int>>&ans, int ind, vector<int>v){
        if(target==0){
            ans.push_back(v);
            return;
        }
        for(int i=ind; i<arr.size(); i++){
            if(i>ind and arr[i]==arr[i-1])
                continue;
            if(arr[i]>target)
                break;
            v.push_back(arr[i]);
            solve(arr, target-arr[i], ans, i+1, v);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>>ans;
        vector<int>v;
        solve(candidates, target, ans, 0, v);
        return ans;
    }
};