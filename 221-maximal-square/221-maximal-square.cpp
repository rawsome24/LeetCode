class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>>v(m, vector<int>(n, 0));
        int mx = 0;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 or j==0){
                    if(mat[i][j]=='1')
                        v[i][j] = 1;
                }
                else
                    if(mat[i][j]=='1')
                        v[i][j] = 1+min(v[i-1][j], min(v[i-1][j-1], v[i][j-1]));
                mx = max(v[i][j], mx);
            }
        }
        // for(int i=0; i<m; i++){
        //     for(int j=0; j<n; j++){
        //         cout<<v[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return mx*mx;
    }
};
