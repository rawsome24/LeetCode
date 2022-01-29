class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n = arr.size();
        int low = 0, high = arr.size()-1,mid=-1;
        while(low<=high)
        {
            mid = low + (high-low)/2;
            if((mid==0 || arr[mid]>arr[mid-1]) && (mid==n-1 || arr[mid]>arr[mid+1]))return mid;
            else if(arr[mid]<arr[mid+1])low = mid+1;
            else high = mid-1;
        }
        if(mid==-1 || mid==arr.size())return INT_MIN;
        else return mid;
    }
};