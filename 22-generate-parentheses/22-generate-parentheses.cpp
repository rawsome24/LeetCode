class Solution {
public:
    void solve(int n, vector<string>&ans, string temp, int open){
        if(temp.size()==n){
            if(open==0)
                ans.push_back(temp);
            return;
        }
        if(open==0){
            temp.push_back('(');
            solve(n, ans, temp, open+1);
            // temp.pop_back();
        }
        else if(open==n/2){
            temp.push_back(')');
            solve(n, ans, temp, open-1);
            // temp.pop_back();
        }
        
        
        else{
            if(open<=n/2 and open>0){
                solve(n, ans, temp+"(", open+1);
                solve(n, ans, temp+")", open-1);
            }
            // temp.pop_back();
        }
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        solve(2*n, ans, "", 0);
        return ans;
    }
};