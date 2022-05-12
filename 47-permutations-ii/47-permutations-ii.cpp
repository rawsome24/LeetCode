class Solution {
public:
    int fact(int n){
        int ans = 1;
        for(int i=n; i>=1; i--)
            ans*=i;
        return ans;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>v;
        set<vector<int>>st;
        for(int i=0; i<fact(nums.size()); i++){
            next_permutation(nums.begin(), nums.end());
            if(st.find(nums)==st.end()){
                ans.push_back(nums);
                st.insert(nums);
            }
        }
        return ans;
    }
};