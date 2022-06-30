class Solution {
public:
    bool solve(vector<vector<char>>&v, string word, int i, int j, int m, int n, int index){
        if (index==word.size())
            return true;
        if(i<0 or j<0 or i>=m or j>=n){
            return false;
        }
        if(v[i][j]!=word[index])
            return false;
        v[i][j]='*';
        bool search = solve(v, word, i+1, j, m, n, index+1) or
                        solve(v, word, i, j+1, m, n, index+1) or
                            solve(v, word, i-1, j, m, n, index+1) or
                                solve(v, word, i, j-1, m, n, index+1);
        v[i][j]=word[index];
        return search;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        string ans="";
        vector<vector<int>>vis(m,vector<int>(n, 0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(word.size()==1){
                    string s(1,board[i][j]);
                    if(word==s)
                        return true;
                }
                else{
                    if(solve(board, word, i, j, m, n, 0))
                        return true;
                }
            }
        }
        return false;
    }
};