class Solution {
public:
    void solve(vector<vector<int>>&ans, vector<int>&arr, int target, int i, vector<int>&v){
        if(i>=arr.size()){
            if(target==0){
                ans.push_back(v);
            }
            return;
        }
        if(arr[i]<=target){
            v.push_back(arr[i]);
            solve(ans, arr, target-arr[i], i, v);
            v.pop_back();
        }
        solve(ans, arr, target, i+1, v);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        // set<vector<int>>st;
        vector<int>v;
        solve(ans, candidates, target, 0, v);
        return ans;
    }
};