class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<pair<int,int>>st;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[i].size(); j++){
                if(matrix[i][j]==0 && st.find({i,j})==st.end()){
                    for(int r=j+1; r<matrix[i].size(); r++)
                        if(matrix[i][r]!=0 && st.find({i,r})==st.end())
                            matrix[i][r]=0, st.insert({i,r});
                    for(int d=i+1; d<matrix.size(); d++)
                        if(matrix[d][j]!=0 && st.find({d,j})==st.end())
                            matrix[d][j]=0, st.insert({d,j});
                    for(int l=j-1; l>=0; l--)
                        if(matrix[i][l]!=0 && st.find({i,l})==st.end())
                            matrix[i][l]=0, st.insert({i,l});
                    for(int u=i-1; u>=0; u--)
                        if(matrix[u][j]!=0 && st.find({u,j})==st.end())
                            matrix[u][j]=0, st.insert({u,j});
                }
            }
        }
    }
};