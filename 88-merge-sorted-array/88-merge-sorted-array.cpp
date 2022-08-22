class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0)
            return;
        if(m==0){
            nums1 = nums2;
            return;
        }
        int first = 0, second = 0, last = m;
        while(first<last and second<n){
            if(nums1[first]>nums2[second]){
                for(int i=m+n-1; i>=first+1; i--)
                    nums1[i] = nums1[i-1];
                nums1[first] = nums2[second];
                first++;
                second++;
                last++;
            }
            else{
                first++;
            }
            // for(int i=0; i<m+n; i++)
            //     cout<<nums1[i]<<" ";
            // cout<<endl;
        }
        while(second<n){
            nums1[first] = nums2[second];
            first++; second++;
        }
    }
};