class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>lMax(height.size(), 0);
        vector<int>rMax(height.size(), 0);
        lMax[0] = height[0];
        for(int i=1; i<height.size(); i++)
            lMax[i] = max(lMax[i-1], height[i]);
        rMax[height.size()-1] = height[height.size()-1];
        for(int i=height.size()-2; i>=0; i--)
            rMax[i] = max(rMax[i+1], height[i]);
        long long ans =0;
        for(int i=1; i<height.size()-1; i++){
            ans += min(lMax[i], rMax[i])-height[i];
        }
        return ans;
    }
};