class Solution {
public:
    vector<int> diStringMatch(string s) {
        int k = 0, j = s.length();
        vector<int>ans;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]=='I'){ans.push_back(k); k++;}
            else {ans.push_back(j); j--;}
        }
        ans.push_back(k);
        return ans;
    }
};