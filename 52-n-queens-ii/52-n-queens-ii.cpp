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
    void solve(vector<string>&res, int&cnt, int col, int n){
        if(col==n){
            cnt++; return;
        }
        for(int i=0; i<n; i++){
            if(isValid(i, col, res, n)){
                res[i][col] = 'Q';
                solve(res, cnt, col+1, n);
                res[i][col] = '.';
            }
        }
        return;
    }
    int totalNQueens(int n) {
        vector<string>v(n, string(n, '.'));
        int cnt=0;
        solve(v, cnt, 0, n);
        return cnt;
    }
};