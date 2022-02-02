class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int i=0, j=0;
        unordered_map<char,int>mp;
        for(int i=0; i<p.length(); i++)mp[p[i]]++;
        vector<int>res;
        int cnt = mp.size();
        while(j<s.length())
        {
            if(mp.find(s[j])!=mp.end())
            {
                mp[s[j]]--;
                if(mp[s[j]]==0)
                    cnt--;
            }
            if(j-i+1<p.length())j++;
            
            
           else if(j-i+1==p.length()){
               if(cnt==0)res.push_back(i);
                
                if(mp.find(s[i])!=mp.end())
                {
                    mp[s[i]]++;
                    if(mp[s[i]]==1)
                        cnt++;
                }
                i++; j++;
            }
        }
        return res;
    }
};