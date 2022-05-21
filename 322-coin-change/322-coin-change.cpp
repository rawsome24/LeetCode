class Solution {
public:
    int t[13][10001];
    int coinChange(vector<int>& coins, int amnt) {
        memset(t, -1, sizeof(t));
        for(int i=0; i<coins.size()+1; i++){
            for(int j=0; j<amnt+1; j++){
                if(i==0)t[i][j] = INT_MAX-1;
                if(j==0)t[i][j]=0;
            }
        }
        // for(int i=1, j=1; j<amnt+1 && i<coins.size(); j++){
        //     if(j%coins[0]==0)
        //         t[i][j]=j/coins[0];
        //     else 
        //         t[i][j] = INT_MAX-1;
        // }
        for(int i=1; i<coins.size()+1; i++){
            for(int j=1; j<amnt+1; j++){
                if(coins[i-1]<=j)
                    t[i][j] = min(1+t[i][j-coins[i-1]], t[i-1][j]);
                else
                    t[i][j] = t[i-1][j];
            }
        }
        
        return t[coins.size()][amnt]==INT_MAX-1?-1:t[coins.size()][amnt];
    }
};