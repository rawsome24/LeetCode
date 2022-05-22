class Solution {
public:
    string longestPalindrome(string s) {
        string res="";
        int l=0, r=s.size()-1;
        int resLen = 0;
        
        for(int i=0; i<s.length(); i++){
            l=i, r=i;
            while(l>=0 && r<s.length() && s[l]==s[r]){
                if(r-l+1>resLen){
                    res.clear();
                    for(int i=l; i<=r; i++)
                        res.push_back(s[i]);
                    resLen = r-l+1;
                }
                l--; r++;
            }
            l=i, r=i+1;
            while(l>=0 && r<s.length() && s[l]==s[r]){
                if(r-l+1>resLen){
                    res.clear();
                    for(int i=l; i<=r; i++)
                        res.push_back(s[i]);
                    resLen = r-l+1;
                }
                l--; r++;
            }
        }
      return res;  
    }
};