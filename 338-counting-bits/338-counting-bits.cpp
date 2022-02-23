class Solution {
public:
    int cntBits(int n)
    {
        int cnt = 0;
        while(n>0)
        {
            n &= (n-1);
            cnt++;
        }
        return cnt;
    }
    
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0; i<=n; i++)
        {
            int cntB = cntBits(i);
            ans.push_back(cntB);
        }
        return ans;
    }
};