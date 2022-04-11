class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<int>v;
        for(auto i=0; i<grid.size(); i++)
        {
            for(auto j=0; j<grid[i].size(); j++)
            {
                v.push_back(grid[i][j]);
            }
        }
        for(int i=0; i<k%v.size(); i++)
        {
            int temp = v[v.size()-1];
            for(int i=v.size()-2; i>=0; i--)
                v[i+1] = v[i];
            v[0] = temp;
        }
        int l = 0;
        for(int i=0; i<grid.size() && l<v.size(); i++)
        {
            for(int j=0; j<grid[i].size(); j++)
                grid[i][j] = v[l], l++;
        }
        return grid;
    }
};