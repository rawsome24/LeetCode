class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans; 
        for(int i=0; i<numRows; i++){
            vector<int>v(i+1);
            v[0] = 1, v[v.size()-1]=1;
            if(v.size()>=3){
                for(int j=1; j<v.size()-1; j++){
                    v[j] = ans[i-1][j-1]+ans[i-1][j];
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};