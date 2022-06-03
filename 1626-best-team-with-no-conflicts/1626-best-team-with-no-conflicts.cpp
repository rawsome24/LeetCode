class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>>v;
        int n = ages.size();
        for(int i = 0;i<n;i++)
        {
            v.push_back({ages[i],scores[i]});
        }
        sort(v.begin(),v.end());
        int dp[n];
        int mx = INT_MIN;
        for(int i = 0;i<n;i++)
        {
            dp[i] = v[i].second;
            for(int j = i-1;j>=0;j--)
            {
                    if(v[i].second>=v[j].second)
                    dp[i] = max(dp[i],dp[j]+v[i].second);               
            }
            mx = max(mx,dp[i]);
        }
        return mx;
    }
};