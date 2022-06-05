class Solution {
public:
    void solve(vector<int>&arr, vector<vector<int>>&v, int target, int n, vector<int>ans){
        if(n>=arr.size())
        {
            if(target==0)
                v.push_back(ans);
            return;
        }
        if(arr[n]<=target)
        {
            ans.push_back(arr[n]);
            solve(arr, v, target-arr[n], n, ans);
            ans.pop_back();
        }
            
        solve(arr, v, target, n+1, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        // set<vector<int>>st;
        vector<vector<int>>v;
        vector<int>ans;
        solve(candidates, v, target, 0, ans);
        return v;
    }
};