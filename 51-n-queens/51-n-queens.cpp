class Solution {
public:
    bool isValid(int row, int col, vector<string>&res, int n){
        for(int i=row; i<n; i++){
            if(res[i][col]=='Q')
                return false;
        }
        for(int i=row; i>=0; i--){
            if(res[i][col]=='Q')
                return false;
        }
        for(int i=col; i<n; i++){
            if(res[row][i]=='Q')
                return false;
        }
        for(int i=col; i>=0; i--){
            if(res[row][i]=='Q')
                return false;
        }
        for(int i=row, j=col; i<n && j<n; i++, j++){
            if(res[i][j]=='Q')
                return false;
        }
        for(int i=row, j=col; i>=0 && j>=0; i--, j--){
            if(res[i][j]=='Q')
                return false;
        }
        for(int i=row, j=col; i>=0 && j<n; i--, j++){
            if(res[i][j]=='Q')
                return false;
        }
        for(int i=row, j=col; i<n && j>=0; i++, j--){
            if(res[i][j]=='Q')
                return false;
        }
        return true;
    }
    void solve(vector<vector<string>>&ans, vector<string>&res, int col, int n){
        if(col==n)
        {
            ans.push_back(res);
            return;
        }
        
        for(int i=0; i<n; i++){
            if(isValid(i, col, res, n)){
                res[i][col]='Q';
                solve(ans, res, col+1, n);
                res[i][col] = '.';
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>res(n, string(n, '.'));
        solve(ans, res, 0, n);
        return ans;
    }
};