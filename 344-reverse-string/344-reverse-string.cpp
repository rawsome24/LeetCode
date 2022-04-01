class Solution {
public:
    /*void solve(int i, int j, vector<char>&s)
    {
        if(i>=j)return;
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        solve(i+1,j-1,s);
    }*/
    
    void reverseString(vector<char>& s) {
        /*int i=0, j=s.size()-1;
        if(i==j)return;
        solve(i,j,s);*/
        reverse(s.begin(), s.end());
    }
};