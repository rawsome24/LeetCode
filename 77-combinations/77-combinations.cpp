class Solution {
public:
    void solve(vector<vector<int>>&ans, int n, int k, vector<int>v, set<vector<int>>&st, int i){
        if(v.size()==k){
            sort(v.begin(), v.end());
            if(st.find(v)==st.end()){
                ans.push_back(v);
            }
            st.insert(v);
            v.clear();
            return;
        }
        for(int j=i; j<=n; j++){
            v.push_back(j);
            solve(ans, n, k, v, st, j+1);
            v.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        set<vector<int>>st;
        vector<int>v;
        solve(ans, n, k, v, st, 1);
        return ans;
    }
};