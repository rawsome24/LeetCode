class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int>mp;
        if(s.length()==0)return 0;
        int j=0,i=0;
        int ans = INT_MIN;
        while(j<s.length()){
            mp[s[j]]++;
            if(mp.size()==j-i+1)
                ans = max(ans, j-i+1), j++;
            else if(mp.size()<j-i+1){
                while(mp.size()<j-i+1){
                    mp[s[i]]--;
                    if(mp[s[i]]==0)
                        mp.erase(s[i]);
                    i++;
                }
                j++;
            }
        }
        if(ans==INT_MIN)return s.length();
        return ans;
    }
};