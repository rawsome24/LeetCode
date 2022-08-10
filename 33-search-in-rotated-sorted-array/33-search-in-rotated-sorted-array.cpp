class Solution {
public:
    int search(vector<int>& arr, int target) {
        int low = 0, high = arr.size()-1;
        
        while(low<=high)
        {
            int mid = low + (high - low)/2;
            
            if(target == arr[mid])
                return mid;
            
            else if(arr[mid]>arr[high] and target<=arr[high])
               low = mid+1;
            else if(arr[mid]<=arr[high] and target>arr[high])
                high = mid-1;
            else{
                if(arr[mid]>target)
                    high = mid-1;
                else if(arr[mid]<target)
                    low = mid+1;
            }
        }
        return -1;
    }
};
