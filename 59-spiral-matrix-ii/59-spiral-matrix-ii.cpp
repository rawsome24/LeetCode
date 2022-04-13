class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > v(n,vector<int>(n,0));  
        int cnt = 1, left = 0, top = n-1, bot = n-1, right = 0;
        while(left<=bot && right<=top)
        {
            for(int i=right; i<=top; i++)
                v[left][i] = cnt, cnt++;
            left++;
            for(int i=left; i<=bot; i++)
                v[i][top] = cnt, cnt++;
            top--;
            for(int i=top; i>=right; i--)
                v[bot][i] = cnt, cnt++;
            bot--;
            for(int i=bot; i>=left; i--)
                v[i][right] = cnt, cnt++;
            right++;
        }
        return v;
    }
};