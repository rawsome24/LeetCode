class Solution {
public:
    int numRescueBoats(vector<int>& p, int limit) {
        sort(p.begin(),p.end());
        int cnt=0;        
        int i=0, j=p.size()-1;
        
        while(i<=j)
        {
           int sum = p[i]+p[j];
            
            if(sum<=limit)
            {
                cnt++; i++; j--;
            }
            
            else if(sum>limit)
            {
                cnt++; j--;
            }
        }
        return cnt;
    }
};