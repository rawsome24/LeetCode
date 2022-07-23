class Solution {
public:
    int dp[301];
    bool solve(string s, set<string>&st, int i){
        if(i==s.length())
            return true;
        if(dp[i]!=-1)
            return dp[i];
        string temp;
        for(int j=i; j<s.length(); j++){
            temp+=s[j];
            if(st.find(temp)!=st.end()){
                if(solve(s, st, j+1))
                    return true;
            }
        }
        return dp[i]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string>st(wordDict.begin(), wordDict.end());
        memset(dp, -1, sizeof(dp));
        return solve(s, st, 0);
    }
};