class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int currMax=arr[0], currMin=arr[0], res=INT_MIN;
        for(auto it:arr)res = max(it, res);
        int ans = res;
        for(int i=1; i<arr.size(); i++){
            if(arr[i]==0)
                currMax = 1, currMin = 1;
            int temp=currMax*arr[i];
            currMax = max(temp, max(currMin*arr[i], arr[i]));
            currMin = min(currMin*arr[i], min(temp, arr[i]));
            ans=max(ans, currMax);
        }
        return ans;
    }
};