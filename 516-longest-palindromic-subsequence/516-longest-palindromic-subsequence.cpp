class Solution {
public:
    int dp[1001][1001];
    int lps(string X, string Y, int n){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(X[i-1]==Y[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][n];
    }
    int longestPalindromeSubseq(string s) {
        string X = s;
        reverse(s.begin(), s.end());
        string Y = s;
        memset(dp, 0, sizeof(dp));
        return lps(X, Y, s.length());
    }
};