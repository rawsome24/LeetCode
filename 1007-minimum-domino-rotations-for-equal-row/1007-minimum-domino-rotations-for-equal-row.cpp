class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        unordered_map<int,int>mp;
        for(auto it:tops)mp[it]++;
        for(auto it:bottoms)mp[it]++;
        
        int mx_val,mx_fr=INT_MIN;
        for(auto it = mp.begin(); it!=mp.end(); it++)
        {
            if(mx_fr<it->second)
            {
                mx_fr = it->second;
                mx_val = it->first;
            }
        }
        if(mx_fr<tops.size())return -1;
        
        int top_fr = 0, bot_fr=0;
        for(int i=0; i<tops.size(); i++)
        {
            if(tops[i]==bottoms[i] && tops[i]==mx_val)continue;
            else if(tops[i]==mx_val)top_fr++;
            else if(bottoms[i]==mx_val)bot_fr++;
            else return -1;
        }
        return min(top_fr,bot_fr);
    }
};