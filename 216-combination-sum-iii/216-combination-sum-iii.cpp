class Solution {
public:
    void solve(int n, int k, vector<int>v, unordered_set<int>&s, set<vector<int>>&st, int startVal){
        if(v.size()==k){
            if(n==0){
                // sort(v.begin(), v.end());
                st.insert(v); 
                return;
            }
            else if(n>0)
                return;
        }
        if(n<0)return;
        for(int i=startVal; i<=9; i++){
            if(i<=n && s.find(i)==s.end()){
                v.push_back(i);
                s.insert(i);
                solve(n-i, k, v, s, st, i+1);
                int val = v[v.size()-1];
                s.erase(val);
                v.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        set<vector<int>>st;
        unordered_set<int>s;
        vector<vector<int>>ans;
        vector<int>v;
        solve(n, k, v, s, st, 1);
        for(auto it=st.begin(); it!=st.end(); it++){
            ans.push_back((*it));
        }
        return ans;
    }
};