class Solution {
public:
    int search(vector<int>& arr, int target) {
        int low = 0, high = arr.size()-1;
        // unordered_set<int>st(arr.begin(), arr.end());
        if(target<arr[low] || target>arr[high])return -1;
        while(low<=high)
        {
            int mid = low + (high - low)/2;
            
            if(arr[mid]==target)
                return mid;
            else if(arr[mid]>target)
                high = mid - 1;
            else 
                low = mid + 1;
        }
        return -1;
    }
};