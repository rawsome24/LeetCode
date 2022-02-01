class Solution {
public:
    int smallestDivisor(vector<int>& num, int threshold) {
        int low = 1, high = 1000000;
        while(low<high)
        {
            int mid = low + (high-low)/2;
            int sum = 0;
            for(int i=0; i<num.size(); i++)
            {
                if(num[i]%mid!=0)sum+=(num[i]/mid)+1;
                else sum+=(num[i]/mid);
            }
            if(sum<=threshold)high = mid;
            else low = mid+1;
        }
        return low;
    }
};