class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int i=0, j=0,cnt=0;
        
        if(s1.length()>s2.length())checkInclusion(s2,s1);
        
        unordered_map<char,int>mp;
        for(auto it:s1)
            mp[it]++;
        
        cnt = mp.size();
        
        while(j<s2.length())
        {
            if(mp.find(s2[j])!=mp.end())
            {
                mp[s2[j]]--;
                if(mp[s2[j]]==0)
                    cnt--;
            }
            
            if(j-i+1<s1.length())j++;
            
            else if(j-i+1==s1.length())
            {
                if(cnt==0)return true;
                else 
                {
                    if(mp.find(s2[i])!=mp.end())
                    {
                        mp[s2[i]]++;
                        if(mp[s2[i]]==1)cnt++;
                    }
                    i++; j++;
                }
            }
        }
        
        return false;
        
    }
};