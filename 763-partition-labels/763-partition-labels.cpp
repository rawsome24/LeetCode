class Solution {
public:
    vector<int> partitionLabels(string s) {
        /*int i=0, j=s.length(),mx = INT_MIN,k=0;
        unordered_set<char>set;
        vector<int>v;
        for(int i=0; i<s.length(); i++)
        {
            for(int j=s.length(); j>=i; j--)
            {
                if(s[j]==s[i] && set.find(s[i])==set.end())
                {mx = max(mx,j); set.insert(s[i]); break;}
            }
            if(mx==i){
                v.push_back(mx-k+1);
                k = i+1;
                mx = INT_MIN;
            }
        }
        return v;*/
        unordered_map<char,int>mp;
        for(int i=0; i<s.length(); i++)
            mp[s[i]]=i;
        vector<int>res;
        int prev=-1, mx = INT_MIN;
        
        for(int i=0; i<s.length(); i++)
        {
            mx = max(mx, mp[s[i]]);
            if(mx==i){
                res.push_back(mx-prev);
                prev = mx;
            }
        }
        return res;
    }
};