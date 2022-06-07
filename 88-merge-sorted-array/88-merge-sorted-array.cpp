class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>ans;
        int first = 0, second = 0;
        while(first<m && second<n){
            if(nums1[first]<=nums2[second]) {ans.push_back(nums1[first]); first++;}
            else if(nums1[first]>nums2[second]){ans.push_back(nums2[second]); second++;}
        }
        if(second==n){
            for(int i=first; i<m; i++)
                ans.push_back(nums1[i]);
        }
        if(first==m){
            for(int i=second; i<n; i++)
                ans.push_back(nums2[i]);
        }
        nums1=ans;
    }
};