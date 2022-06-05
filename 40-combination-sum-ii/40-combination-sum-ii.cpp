class Solution {
public:
    void solve(vector<int>&arr, int target, vector<vector<int>>&v, vector<int>ans, int n){
        if(target==0){
            v.push_back(ans);
            return;
        }
            
        for(int i=n; i<arr.size(); i++){
            if(i>n && arr[i]==arr[i-1])continue;
            if(arr[i]>target)break;
            ans.push_back(arr[i]);
            solve(arr, target-arr[i], v, ans, i+1);
            ans.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>>v;
        vector<int>ans;
        solve(candidates, target, v, ans, 0);
        return v;
    }
};