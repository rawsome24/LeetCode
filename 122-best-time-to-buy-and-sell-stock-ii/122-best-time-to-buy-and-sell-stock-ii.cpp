class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        int ans = 0, bp = p[0];
        for(int i=1; i<n; ++i){
            if(p[i]>bp) ans += p[i]-bp;
            bp = p[i];
        }
        return ans;
    }
};