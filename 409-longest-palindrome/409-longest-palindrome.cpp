class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<int,int>mp;
        for(int i=0; i<s.length(); i++)
            mp[s[i]]++;
        int ans = 0;
        bool flag = false;
        for(auto it=mp.begin(); it!=mp.end(); it++){
            if(it->second%2==0)
                ans+=it->second;
            else if(it->second%2!=0)
                {ans += it->second-1; flag =  true;}
        }
        if(flag)
            ans++;
        return ans;
         
    }
};