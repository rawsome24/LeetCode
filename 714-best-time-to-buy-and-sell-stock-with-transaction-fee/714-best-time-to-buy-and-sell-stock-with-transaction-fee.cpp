class Solution {
public:
    map<pair<int,int>, int>mp;
    int solve(vector<int>&v, int fee, int i, int buy){
        if(i>=v.size())
            return 0;
        
        if(mp.find({i,buy})!=mp.end())
            return mp[{i,buy}];
        
        if(buy){
            int x = solve(v, fee, i+1, 0)+v[i]-fee;
            int y = solve(v, fee, i+1,  1);
            return mp[{i,buy}] = max(x,y);
        }
        else{
            int x = solve(v, fee, i+1, 1)-v[i];
            int y = solve(v, fee, i+1, 0);
            return mp[{i,buy}] = max(x, y);
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        // memset(dp, -1, sizeof(dp));
        return solve(prices, fee, 0, 0);
    }
};

