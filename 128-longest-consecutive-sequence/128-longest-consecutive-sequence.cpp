class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(), nums.end());
        int len = 0;
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            if(st.find(nums[i]-1)==st.end()){
                int val = nums[i];
                len = 0;
                while(st.find(val)!=st.end()){
                    val++;len++;
                    ans = max(len, ans);
                }
            }
        }
        return ans;
    }
};