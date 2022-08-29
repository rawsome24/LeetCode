class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>v;
        for(int i=1; i<=n; i++){
            v.push_back(i);
        }
        k--;
        while(k--){
            next_permutation(v.begin(), v.end());
        }
        string ans;
        for(auto it:v){
            ans.push_back(it+'0');
        }
        return ans;
    }
};