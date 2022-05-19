class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(), nums.end());
        int ans = 0;
        for(auto it:nums){
            int len = 1;
            if(st.find(it-1)==st.end()){
                while(st.find(it+len)!=st.end())
                    len++;
                ans = max(len, ans);
            }
        }
        return ans;
    }
};