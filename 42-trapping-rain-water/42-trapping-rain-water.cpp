class Solution {
public:
    int trap(vector<int>& h) {
        
        /***************NAIVE*****************/
        /*
        int amnt = 0;
        for(int i=1; i<h.size()-1; i++)
        {
            int lMax = h[i];
            for(int j=0; j<i; j++)
                lMax = max(h[j],lMax);
            int rMax = h[i];
            for(int j=i; j<h.size(); j++)
                rMax = max(h[j],rMax);
            amnt += min(lMax-rMax)-h[i];
        }
        return amnt;
        */
        /************OPTIMIZED***************/
        /*Precomputed lMax and rMax and store in array*/
        
        int lMax[h.size()],rMax[h.size()];
        int amnt = 0;
        
        lMax[0] = h[0];
        for(int i=1; i<h.size(); i++)
            lMax[i] = max(lMax[i-1],h[i]);
        
        rMax[h.size()-1] = h[h.size()-1];
        for(int i=h.size()-2; i>=0; i--)
            rMax[i] = max(rMax[i+1],h[i]);
        
        for(int i=1; i<h.size()-1; i++)
            amnt+=min(lMax[i],rMax[i])-h[i];
        
        return amnt;
    }
};