class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<m; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i=0; i<n; i++){
            int l = 0, h = m-1;
            while(l<=h){
                swap(matrix[i][l], matrix[i][h]);
                l++, h--;
            }
        }
    }
};