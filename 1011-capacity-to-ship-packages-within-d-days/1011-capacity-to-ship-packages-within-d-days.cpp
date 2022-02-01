class Solution {
public:
    int shipWithinDays(vector<int>& wei, int days) {
        int mx = INT_MIN,sum=0;
        for(int i=0; i<wei.size(); i++){
            mx = max(wei[i],mx);
            sum+=wei[i];
        }
        int low = mx, high = sum;
        while(low<high)
        {
            int mid = low + (high-low)/2;
            int cnt = 1, sum = 0;
            for(int i=0; i<wei.size();i++)
            {
                sum += wei[i];
                if(sum>mid){
                    cnt++;
                    sum = wei[i];
                }
            }
            // if(sum<mid)cnt++;
            if(cnt<=days){high= mid;}
            else low = mid+1;
        }
        return low;
    }
};