class Solution {
public:
    int dp[1001];
    int solve(int ind, vector<int>&cost){
        if(ind>=cost.size()){
            return 0;
        }
        if(dp[ind]!=-1)
            return dp[ind];
        int sum1 = cost[ind]+solve(ind+1, cost);
        int sum2= cost[ind]+solve(ind+2, cost);
        return dp[ind]=min(sum1, sum2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp, -1, sizeof(dp));
        return min(solve(0, cost), solve(1,cost));
    }
};