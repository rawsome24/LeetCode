class Solution {
public:
    int search(vector<int>& arr, int target) {
        int low = 0, high = arr.size()-1;
        
        while(low<=high)
        {
            int mid = low + (high - low)/2;
            
            if(target == arr[mid])
                return mid;
            
            else if(arr[low]<=arr[mid])
            {
                if(target>=arr[low] && target<arr[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else
            {
                if(target<=arr[high] && arr[mid]<target)
                    low = mid+1;
                else
                    high = mid - 1;
            }
        }
        return -1;
    }
};
