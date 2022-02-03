class Solution {
public:
    int countGoodSubstrings(string s) {
        int k = 3,cnt=0;
        int i=0,j=0;
        int h[256]={0};
        while(j<s.length())
        {        
            h[s[j]]++;
            if(j-i+1<k)j++;
            
            else if(j-i+1==k)
            {
                bool flag = false;
                for(int l=i; l<=j; l++){
                if(h[s[l]]>=2){flag=true; break;}
                }
                if(!flag)cnt++;
                h[s[i]]--;
                i++; j++;
            }
        }
        return cnt;
    }
};