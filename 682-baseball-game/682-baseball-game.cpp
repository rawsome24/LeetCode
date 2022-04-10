class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int>v;
        for(auto it:ops)
        {
            if(it=="C")
                v.pop_back();
            else if(it=="D")
            {
                int a = v[v.size()-1]*2;
                v.push_back(a);
            }
            else if(it=="+")
            {
                int a = v[v.size()-1]+v[v.size()-2];
                v.push_back(a);
            }
            else
                v.push_back(stoi(it));
        }
        int ans= 0;
        for(auto it:v)
            ans+=it;
        return ans;
    }
};