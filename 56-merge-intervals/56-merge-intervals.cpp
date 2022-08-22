class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>>ans;
        vector<int>temp = intervals[0];
        for(int i=0; i<intervals.size(); i++){
            if(temp[1]>=intervals[i][0]){
                temp[1] = max(temp[1], intervals[i][1]);
            }else{
                ans.push_back(temp);
                temp = intervals[i];
            }
        }
        ans.push_back(temp);
        return ans;
    }
};