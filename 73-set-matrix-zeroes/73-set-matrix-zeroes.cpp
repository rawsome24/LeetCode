class Solution {
public:
    void setZeroes(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        vector<int>row(n, -1);
        vector<int>col(m, -1);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(arr[i][j]==0){
                    col[j] = 0;
                    row[i] = 0;
                }
            }
        }
        // cout<<row[1];
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++)
                if(row[i]==0)
                    arr[i][j] = 0;
        }

        for(int j=0; j<m; j++){
            for(int i=0; i<n; i++)
                if(col[j]==0)
                    arr[i][j] = 0;
        }
    }
};