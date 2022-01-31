class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int h[1001]={0};
        if(nums1==nums2)return nums2;
         vector<int>ans;
        if(nums1.size()<=nums2.size()){
            for(int i=0; i<nums1.size(); i++)
                if(h[nums1[i]]==0)h[nums1[i]]++;
           
            
            for(int i=0; i<nums2.size(); i++)
            {
                if(h[nums2[i]]==1){
                    ans.push_back(nums2[i]);
                    h[nums2[i]]=0;
                }
            }
        }
        else {
            for(int i=0; i<nums2.size(); i++)
                if(h[nums2[i]]==0)h[nums2[i]]++;
            
            for(int i=0; i<nums1.size(); i++)
            {
                if(h[nums1[i]]==1){
                    ans.push_back(nums1[i]);
                    h[nums1[i]]=0;
                }
            }
        }
        return ans;
    }
};