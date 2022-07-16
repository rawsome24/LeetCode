class Solution {
public:
    int dp[366];
    int solve(vector<int>&days, vector<int>&costs, int i, map<int, bool>&mp){
        if(i>365)
            return 0;
        if(!mp[i])
            return solve(days, costs, i+1, mp);
        if(dp[i]!=-1)
            return dp[i];
        int buyDayPass = costs[0]+solve(days, costs, i+1, mp);
        int buyWeekPass = costs[1]+solve(days, costs, i+7, mp);
        int buyMonthPass = costs[2]+solve(days, costs, i+30, mp);
        return dp[i] = min(buyDayPass, min(buyWeekPass, buyMonthPass));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        map<int, bool>mp;
        for(int i=1; i<=365; i++)
            mp[i] = false;
        for(auto x:days){
            mp[x] = true;
        }
        memset(dp, -1, sizeof(dp));
        return solve(days, costs, 0, mp);
    }
};