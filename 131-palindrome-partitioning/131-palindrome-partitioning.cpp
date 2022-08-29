class Solution {
public:
    bool isPalindrome(string str, int i, int j){
        while(i<=j){
            if(str[i]!=str[j])
                return false;
            i++; j--;
        }
        return true;
    }
    void solve(string s, int i, vector<vector<string>>&ans, vector<string>&v){
        if(i==s.length()){
            ans.push_back(v);
            return;
        }
        for(int j=i; j<s.length(); j++){
            if(isPalindrome(s, i, j)){
                v.push_back(s.substr(i, j-i+1));
                solve(s, j+1, ans, v);
                v.pop_back();
            }
        }
        
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>v;
        solve(s, 0, ans, v);
        return ans;
    }
};