class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.length();
        int i=0, j=n-1,cnt0=0,cnt1=0;
        
        while(i<=j)
        {
            if(s[i]==s[j])
            {
                i++; j--;
            }
            else {
                i++; cnt0++;
            }
        }
        i=0; j=n-1;
        while(i<=j)
        {
            if(s[i]==s[j])
            {
                i++; j--;
            }
            else {
                j--; cnt1++;
            }
        }
        if(cnt1==0 || cnt0==0)return true;
        else if(cnt1==1 || cnt0==1)return true;
        else return false;
    }
};