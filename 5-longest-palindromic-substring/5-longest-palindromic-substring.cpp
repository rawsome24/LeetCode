class Solution {
public:
    string longestPalindrome(string s) {
        string res="";
        int len=0;
        for(int i=0; i<s.size(); i++){
            int l=i,r=i;
            while(l>=0 and r<s.size() and s[l]==s[r]){
                if(r-l+1>len){
                    res.erase();
                    for(int i=l; i<=r; i++)
                        res.push_back(s[i]);
                    len = r-l+1;
                }
                l--; r++;
            }
            l = i; r = i+1;
            while(l>=0 and r<s.size() and s[l]==s[r]){
                if(r-l+1>len){
                    res.erase();
                    for(int i=l; i<=r; i++)
                        res.push_back(s[i]);
                    len = r-l+1;
                }
                l--; r++;
            }
        }
        return res;
    }
};