class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int mod = 1e9+7;
        if(horizontalCuts[0]!=0)
            horizontalCuts.push_back(0);
        if(horizontalCuts[horizontalCuts.size()-1]!=h)
            horizontalCuts.push_back(h);
        if(verticalCuts[verticalCuts.size()-1]!=w)
            verticalCuts.push_back(w);
        if(verticalCuts[0]!=0)
            verticalCuts.push_back(0);
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        long long x = LLONG_MIN, y = LLONG_MIN;
        for(int i=0; i<horizontalCuts.size()-1; i++){
            x = max(x, (long long)(horizontalCuts[i+1]-horizontalCuts[i]));
        }
        for(int i=0; i<verticalCuts.size()-1; i++){
            y = max(y, (long long)(verticalCuts[i+1]-verticalCuts[i]));
        }
        long long int ans = ((x%mod)*(y%mod))%mod;
        return (long long) ans;
    }
};