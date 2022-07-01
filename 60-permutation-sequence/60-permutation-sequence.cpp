class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>v;
        for(int i=1; i<=n; i++){
            v.push_back(i);
        }
        while(k-1){
            next_permutation(v.begin(), v.end());
            k--;
        }
        string ans = "";
        for(auto it:v){
            ans.push_back(it+'0');
        }
        return ans;
    }
};