class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPro = 0, minPrice = prices[0];
        for(int i=0; i<prices.size(); i++){
            minPrice = min(minPrice, prices[i]);
            maxPro = max(maxPro, prices[i]-minPrice);
        }
        return maxPro;
    }
};