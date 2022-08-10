class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind1 = -1, ind2 = -1;
        for(int i=nums.size()-2; i>=0; i--){
            if(nums[i]<nums[i+1])
                {ind1 = i; break;}
        }
        for(int i=nums.size()-1; i>=0; i--){
            if(ind1!=-1 and nums[ind1]<nums[i])
                {ind2 = i; break;}
        }
        if(ind1!=-1 and ind2!=-1)
            swap(nums[ind1], nums[ind2]);
        int i = ind1+1, j = nums.size()-1;
        while(i<nums.size() and i<=j){
            swap(nums[i], nums[j]);
            i++; j--;
        }
    }
};