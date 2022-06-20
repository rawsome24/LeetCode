class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        vector<vector<int>>ans(mat.size(), vector<int>(mat[0].size(),0));
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat[0].size(); j++){
                int sum = 0;
                for(int indx = i-k; indx<=i+k; indx++){
                    for(int indy=j-k; indy<=j+k; indy++){
                        if(indx>=0  && indy>=0 && indx<mat.size() && indy<mat[0].size())
                            sum+=mat[indx][indy];
                    }
                }
                ans[i][j] = sum;
            }
        }
        return ans;
    }
};