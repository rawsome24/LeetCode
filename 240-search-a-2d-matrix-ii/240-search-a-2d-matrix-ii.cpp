class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0, j = matrix[0].size()-1;
        while(i>=0 and j>=0 and i<matrix.size() and j<matrix[0].size()){
            if(target==matrix[i][j])
                return true;
            if(target>matrix[i][j])
                i++;
            else
                j--;
        }
        return false;
    }
};