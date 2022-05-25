class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<pair<int,int>>p(intervals.size());
        for(int i=0; i<intervals.size(); i++){
            p[i].first = intervals[i][0];
            p[i].second = intervals[i][1];
        }
        p.push_back({newInterval[0], newInterval[1]});
        sort(p.begin(), p.end());
        for(int i=0; i<p.size()-1; i++){
            if(p[i].second>=p[i+1].first){
                p[i].second = max(p[i+1].second, p[i].second);
                p.erase(p.begin()+i+1);
                i--;
            }
        }
        vector<vector<int>>ans;
        for(int i=0; i<p.size(); i++){
            vector<int>v={p[i].first, p[i].second};
            ans.push_back(v);
        }
        return ans;
    }
};