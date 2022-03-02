class Solution {
public:
    int dp[101][10001];
    void lcs(string X, string Y, int m, int n)
    {
        memset(dp,0,sizeof(dp));
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(X[i-1]==Y[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else 
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    bool isSubsequence(string s, string t) {
        lcs(s, t, s.length(), t.length());
        return (dp[s.length()][t.length()]==s.length());
    }
};