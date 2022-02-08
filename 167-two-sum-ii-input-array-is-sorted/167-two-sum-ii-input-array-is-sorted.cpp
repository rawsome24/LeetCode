class Solution {
public:
    vector<int> twoSum(vector<int>& num, int target) {
        int i=0,j=num.size()-1;
        vector<int>ans;
        while(i<j)
        {
            if(num[i]+num[j]==target)
            {
                ans = {i+1,j+1};
                return ans;
            }
            else if(num[i]+num[j]>target)
                j--;
            else i++;
        }
        return ans;
    }
};