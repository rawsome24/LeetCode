class Solution {
public:
    string minWindow(string s, string t) {
        int i=0, j=0;
        unordered_map<char, int>mp1;
        unordered_map<char, int>mp2;
        
        if(t.length()>s.length())
            return "";
        
        int cntmp1=0, cntmp2=0;
        
        for(int k=0; k<t.length(); k++)
            mp1[t[k]]++;
        
        for(auto [key,value]:mp1)
            cntmp1+=value;
        
        pair<int, int>p;
        int ans = INT_MAX;
        while(j<s.length()){
            if(mp1.find(s[j])!=mp1.end())
            {
                mp2[s[j]]++;
                if(mp2[s[j]]<=mp1[s[j]])
                    cntmp2++;
            }
            
            if(cntmp2<cntmp1)
                j++;
            
            else if(cntmp1==cntmp2)
            {
               while(cntmp1==cntmp2)
               {
                   if(mp1.find(s[i])!=mp1.end())
                   {
                       if(j-i+1<ans)
                           p.first = i, p.second = j, ans = j-i+1;
                       mp2[s[i]]--;
                       if(mp2[s[i]]<mp1[s[i]])
                           cntmp2--;
                   }
                   i++;
               }
                j++;
            }
        }
        string res = "";
        if(ans==INT_MAX)return res;
        for(int i=p.first; i<=p.second; i++)
            res.push_back(s[i]);
        return res;
    }
};