class Solution {
public:
    int fO(vector<int>&arr, int target){
        int low = 0, high = arr.size()-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(arr[mid]<target)
                low = mid+1;
            else if(arr[mid]>target)
                high = mid-1;
            else{
                if(mid==0 or arr[mid]!=arr[mid-1])
                    return mid;
                else
                    high=mid-1;
            }
        }
        return -1;
    }
    int lO(vector<int>&arr, int target){
        int low = 0, high = arr.size()-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(arr[mid]>target)
                high = mid-1;
            else if(arr[mid]<target)
                low = mid+1;
            else{
                if(mid==arr.size()-1 or arr[mid]!=arr[mid+1])
                    return mid;
                else
                    low = mid+1;
            }
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int firstOccur = fO(nums, target);
        int lastOccur = lO(nums, target);
        if(firstOccur==-1)
            return {-1, -1};
        else
            return {firstOccur, lastOccur};
    }
};