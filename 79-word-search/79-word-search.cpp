class Solution {
public:
    bool solve(vector<vector<char>>&v, int m, int n, string word, string temp, int i, int j, int k){
        if(k==word.length())
            return true;
        if(i<0 or j<0 or i>=m or j>=n or k>=word.length())
            return false;
        if(v[i][j]!=word[k])
            return false;
        v[i][j] = '*';
        bool flag = solve(v, m, n, word, temp, i+1, j, k+1)
                        or solve(v, m, n, word, temp, i, j+1, k+1) 
                            or solve(v, m, n, word, temp, i-1, j, k+1) 
                                or solve(v, m, n, word, temp, i, j-1, k+1);
        v[i][j] = word[k];
        return flag;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        string temp = "";
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++)
               if(solve(board, board.size(), board[0].size(), word, "", i, j, 0))
                   return true;
        }
        return false;
    }
};