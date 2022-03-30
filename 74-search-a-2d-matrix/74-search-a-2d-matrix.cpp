class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        for(int i=0, j=mat[0].size()-1; i<=mat.size()-1 && j>=0;)
        {
            if(target==mat[i][j])
                return true;
            else if(target>mat[i][j])
                i++;
            else if(target<mat[i][j])
                j--;
        }
        return false;
    }
};