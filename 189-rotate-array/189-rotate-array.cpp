class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       /* while(k)
        {
            int temp = nums[nums.size()-1];
            for(int i=nums.size()-1; i>0; i--)
                nums[i] = nums[i-1];
            nums[0] = temp;
            k--;
        }
        */
        
        vector<int> v;
        int n = nums.size();
        if(k>=n) k = k%n;
        else if(k==0) return;
        for(int i=n-1; i>=n-k ; i--) v.push_back(nums[i]);
        for(int i=n-1-k; i>=0; i--) nums[i+k] = nums[i];
        for(int i=0; i<k ; i++) nums[i] = v[k-1-i];
    }
};