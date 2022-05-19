class Solution {
public:
    int firstPos(vector<int>&arr, int x){
        int low = 0, high = arr.size()-1;
        
        while(low<=high){
            int mid = low + (high-low)/2;
            
            if(arr[mid]>x)
                high = mid-1;
            
            else if(arr[mid]<x)
                low = mid+1;
            
            else{
                
                if(mid==0 || arr[mid]!=arr[mid-1])
                    return mid;
                else 
                    high = mid-1;
            }
        }
        return -1;
    }
     int lastPos(vector<int>&arr, int x){
        int low = 0, high = arr.size()-1;
        
        while(low<=high){
            int mid = low + (high-low)/2;
            
            if(arr[mid]>x)
                high = mid-1;
            
            else if(arr[mid]<x)
                low = mid+1;
            
            else{
                
                if(mid==arr.size()-1 || arr[mid]!=arr[mid+1])
                    return mid;
                else 
                    low = mid+1;
            }
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& arr, int target) {
        int fO = firstPos(arr,target);
        int lO = lastPos(arr,target);
        return {fO, lO};
    }
};