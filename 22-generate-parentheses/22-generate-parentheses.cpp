class Solution {
public:
    void solve(int n, vector<string>&ans, string v, int open, int close){
        if(open==n && close==n){
            ans.push_back(v);
            return;
        }
        
        if(open<n){
            v.push_back('(');
            solve(n, ans, v, open+1, close);
            v.pop_back();
        }
        if(close<open){
            v.push_back(')');
            solve(n, ans, v, open, close+1);
            v.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int cnt = 0;
        solve(n, ans, "", 0, 0);
        return ans;
    }
};