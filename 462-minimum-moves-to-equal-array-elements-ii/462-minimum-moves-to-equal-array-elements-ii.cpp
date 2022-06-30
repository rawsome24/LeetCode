class Solution {
public:
    int minMoves2(vector<int>& num) {
        sort(num.begin(), num.end());
        int diff = num[num.size()/2];
        int ans = 0;
        for(auto it:num){
            ans+=abs(it-diff);
        }
        return ans;
    }
};