class Solution {
public:
    int dp[1001][1002];
    int solve(vector<vector<int>>&pairs, int ind, int prev_ind){
        if(ind==pairs.size())
            return 0;
        if(dp[ind][prev_ind+1]!=-1)
                return dp[ind][prev_ind+1];
        int len = 0+solve(pairs, ind+1, prev_ind);
        if(prev_ind==-1 or pairs[ind][0]>pairs[prev_ind][1])
            len = max(len, 1+solve(pairs, ind+1, ind));
        return dp[ind][prev_ind+1]=len;
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        memset(dp, -1, sizeof(dp));
        return solve(pairs, 0, -1);
    }
};