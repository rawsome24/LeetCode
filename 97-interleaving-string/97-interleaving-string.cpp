class Solution {
public:
    int dp[101][101];
    bool solve(string s1, string s2, string s3, int i, int j, int k){
        if(k==s3.length())
            return true;
        bool case1=false ,case2=false;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(i<s1.length() and s1[i]==s3[k])
            case1 = case1 or solve(s1, s2, s3, i+1, j, k+1);
        if(j<s2.length() and s2[j]==s3[k])
            case2 = case2 or solve(s1, s2, s3, i, j+1, k+1);
        return dp[i][j]=(case1 or case2);
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.length()!=(s1.length()+s2.length()))
            return false;
        memset(dp, -1, sizeof(dp));
        return solve(s1, s2, s3, 0, 0, 0);
    }
};