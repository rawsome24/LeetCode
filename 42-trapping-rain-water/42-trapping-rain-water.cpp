class Solution {
public:
    int trap(vector<int>& h) {
        int res = 0;
        int lMax[h.size()];
        lMax [0] = h[0];
        for(int i=1; i<h.size(); i++){
            lMax[i] = max(lMax[i-1], h[i]);
        }
        int rMax[h.size()];
        rMax[h.size()-1] = h[h.size()-1];
        for(int i=h.size()-2; i>=0; i--){
            rMax[i] = max(rMax[i+1], h[i]);
        }
        for(int i=1; i<h.size()-1; i++){
            res+=min(lMax[i],rMax[i])-h[i];
        }
        return res;
    }
};