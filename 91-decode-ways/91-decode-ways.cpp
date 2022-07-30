class Solution {
public:
    int dp[101];
    int solve(string str, int i){
        if(i==str.length())
            return 1;
        // if(i==str.length()-1)
        //     return 1;
        if(dp[i]!=-1)
            return dp[i];
        if(str[i]=='0')
            return 0;
        int res = solve(str, i+1);
        if(i+1<str.length() and (str[i]=='1' or (str[i]=='2' and (str[i+1]>='0' and str[i+1]<='6'))))
            res+=solve(str, i+2);
        return dp[i]=res;
    }
    int numDecodings(string s) {
        memset(dp, -1, sizeof(dp));
        return solve(s, 0);
    }
};