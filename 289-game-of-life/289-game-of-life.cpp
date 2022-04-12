class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>>v(n,vector<int>(m,0));
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                int c = 0;
                if(i+1<n && board[i+1][j] == 1)
                c++;
                if(i+1<n && j-1>=0 && board[i+1][j-1] == 1 )
                c++;
                if(i+1<n && j+1<m && board[i+1][j+1] == 1)
                c++;
                if(i-1>=0 && board[i-1][j] == 1)
                c++;
                if(i-1>=0 && j-1>=0 && board[i-1][j-1] == 1)
                c++;
                if(i-1>=0 && j+1<m && board[i-1][j+1] == 1)
                c++;
                if(j+1<m && board[i][j+1] == 1)
                c++;
                if(j-1>=0 && board[i][j-1] == 1)
                c++;   
                if(board[i][j] == 1)
                { 
                    if(c<2 || c>3)
                    v[i][j] = 0;
                    if(c == 2 || c == 3)
                    v[i][j] = 1;
                }
                else
                {
                    if(c == 3)
                        v[i][j] = 1;
                }
               
            }
        }
        board = v;
    }
};