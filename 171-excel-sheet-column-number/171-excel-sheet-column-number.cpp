class Solution {
public:
    int titleToNumber(string cT) {
        int ans = 0, n = cT.length();
        for(int i=n-1; i>=1; i--)
            ans+=pow(26,i);
        for(int i=0; i<n; i++)
            ans += pow(26,n-i-1)*(cT[i]-65);
        return ++ans;
    }
};