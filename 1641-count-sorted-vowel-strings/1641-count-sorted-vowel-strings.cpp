class Solution {
public:
    int countVowelStrings(int n) {
        int dp[n+1][5];
        for(int i=0; i<5; i++){
            dp[0][i] = 1;
        }
        for(int i=1; i<=n; i++){
            dp[i][4] = 1;
            for(int j=3; j>=0; j--)
                dp[i][j] = dp[i-1][j] + dp[i][j+1];
        }
        return dp[n][0];
    }
};