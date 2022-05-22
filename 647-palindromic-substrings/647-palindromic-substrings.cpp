class Solution {
public:
    int countSubstrings(string s) {
        int cnt=0;
        vector<string>v;
        for(int i=0; i<s.length(); i++){
            int l=i, r=i;
            
            while(l>=0 && r<s.length() && s[l]==s[r]){
                cnt++;
                l--, r++;
            }
            l=i, r=i+1;
            while(l>=0 && r<s.length() && s[l]==s[r]){
                cnt++;
                l--, r++;
            }
        }
        return cnt;
    }
};