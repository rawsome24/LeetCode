class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        vector<int>ans;
        int left = 0, top = 0, right = mat[0].size()-1, bot = mat.size()-1;
        while(left<=right && top<=bot)
        {
            for(int i=left; i<=right; i++)
                ans.push_back(mat[top][i]);
            top++;
            for(int i=top; i<=bot; i++)
                ans.push_back(mat[i][right]);
            right--;
            if(top<=bot)
            {
                    for(int i=right; i>=left; i--)
                    ans.push_back(mat[bot][i]); 
                bot--;
            }
            if(left<=right)
            {
                for(int i=bot; i>=top; i--)
                    ans.push_back(mat[i][left]);
                left++;
            }
            // if(left>bot || right>top)break;
        }
        return ans;
    }
};