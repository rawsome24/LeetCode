class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPro = INT_MIN;
        int minPrice = INT_MAX;
        for(int i=0; i<prices.size(); i++)
        {
            minPrice = min(minPrice,prices[i]);
            maxPro = max(prices[i]-minPrice, maxPro);
        }
        return maxPro;
    }
};