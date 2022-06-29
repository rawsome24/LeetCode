class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        vector<int>v;
        int left=0, top=mat[0].size()-1, right=0, bottom = mat.size()-1;
        while(left<=bottom && right<=top){
            if(right<=top and left<=bottom){
                for(int i=right; i<=top; i++){
                    v.push_back(mat[left][i]);
                }
                left++;
            }
            if(left<=bottom and right<=top){
                for(int i=left; i<=bottom; i++){
                    v.push_back(mat[i][top]);
                }
                top--;
            }
            if(right<=top and left<=bottom){
                for(int i=top; i>=right; i--){
                    v.push_back(mat[bottom][i]);
                }
                bottom--;
            }
            if(left<=bottom and right<=top){
                for(int i=bottom; i>=left; i--){
                    v.push_back(mat[i][right]);
                }
                right++;
            }
        }
        return v;
    }
    
};