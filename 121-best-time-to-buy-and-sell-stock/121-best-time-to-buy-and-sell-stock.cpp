class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mnPrice = INT_MAX;
        int ans = 0;
        for(int i=0; i<prices.size(); i++){
            mnPrice = min(prices[i], mnPrice);
            ans = max(ans, prices[i]-mnPrice);
        }
        return ans;
    }
};