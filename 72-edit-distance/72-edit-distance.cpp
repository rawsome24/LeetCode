class Solution {
public:
    int dp[501][501];
    int solve(string word1, string word2, int i, int j){
        if(j>=word2.length() and i<word1.length())
            return word1.length()-i;
        if(i>=word1.length() and j<word2.length())
            return word2.length()-j;
        if(i>=word1.length() or j>=word2.length())
            return 0;
        if(word1[i]==word2[j])
            return 0+solve(word1, word2, i+1, j+1);
        if(dp[i][j]!=-1)
            return dp[i][j];
        int case1 = 1+solve(word1, word2, i+1, j+1);
        int case2 = 1+solve(word1, word2, i+1, j);
        int case3 = 1+solve(word1, word2, i, j+1);
        return dp[i][j]=min(case1, min(case2, case3));
    }
    int minDistance(string word1, string word2) {
        memset(dp, -1, sizeof(dp));
        return solve(word1, word2,  0, 0);
    }
};

//ros
//ro