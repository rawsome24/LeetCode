class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int mx = values[0]-1, res = INT_MIN;
        for(int i = 1; i<values.size(); i++, --mx){
            res = max(res, values[i]+mx);
            mx = max(mx, values[i]);
        }
        return res;
    }
};