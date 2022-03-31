class Solution {
public:
    bool isTrue(vector<int>v, int sum, int m)
    {
        int curr_sum=0, freq = 1;
        for(int i=0; i<v.size(); i++)
        {
            if(curr_sum+v[i]>sum)
            {
                curr_sum=v[i];
                freq++;
            }
            else curr_sum+=v[i];
        }
        return (freq<=m);
    }
    int splitArray(vector<int>& arr, int m) {
        int sum=0, mx = INT_MIN;
        for(auto it:arr)sum+=it;
        for(auto it:arr){
            mx = max(mx, it);
        }
        int low = mx, high = sum;
        int res  = 0;
        while(low<=high)
        {
            int mid = low + (high - low)/2;
            if(isTrue(arr, mid, m))
            {
                res = mid;
                high = mid-1;
            }
            else
                low = mid + 1;
        }
        return res;
    }
};