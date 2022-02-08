class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        
       sort(nums.begin(),nums.end());
        /*if(nums[0]>0)
        {
            int sum1=0;
            if(k%2)nums[0]=-nums[0];
            for(auto it:nums)
                sum1+=it;
            return sum1;
        }*/
        for(int i=0; i<nums.size()&& k>0; i++)
        {
            if(nums[i]<0){nums[i]=-nums[i]; k--;}
            else if(nums[i]==0){k=0; break;}
            else if(nums[i]>0)break;
        }
        if(k>0){
            sort(nums.begin(),nums.end());
            if(k%2)nums[0]=-nums[0];
        }
        int sum=0;
        for(auto it:nums)
            sum+=it;
        return sum;
    }
};