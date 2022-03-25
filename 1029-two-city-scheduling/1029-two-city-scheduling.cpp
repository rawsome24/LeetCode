class Solution {
public:
    struct myCmp{
        bool operator()(vector<int>&a, vector<int>&b)
        {
            return a[0]-a[1]<b[0]-b[1];
        }
    };
    int twoCitySchedCost(vector<vector<int>>& c) {
        sort(c.begin(), c.end(), myCmp());
        int ans = 0;
        for(int i=0; i<c.size()/2; i++)
            ans+=c[i][0];
        for(int i=c.size()/2; i<c.size(); i++)
            ans+=c[i][1];
        return ans;
    }
};