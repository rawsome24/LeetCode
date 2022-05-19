class Solution {
public:
    void sortColors(vector<int>& arr) {
        int mid=0, low=0, high = arr.size()-1;
        while(mid<=high){
            if(arr[mid]==0){
                swap(arr[low],arr[mid]);
                low++; mid++;
            }
            else if(arr[mid]==1)
                mid++;
            else if(arr[mid]==2){
                swap(arr[high], arr[mid]);
                high--;
            }
        }
    }
};