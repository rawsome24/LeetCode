class Solution {
public:
    bool search(vector<int>& arr, int target) {
        unordered_set<int>st(arr.begin(), arr.end());
        return (st.find(target)!=st.end());
    }
};