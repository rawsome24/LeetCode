class Solution {
public:
    void sortColors(vector<int>& arr) {
        int low = 0, high = arr.size()-1;
        int mid = 0;
        while(mid<=high){
            if(arr[mid]==0){
                swap(arr[low], arr[mid]);
                mid++; low++;
            }
            else if(arr[mid]==1){
                mid++;
            }
            else{
                swap(arr[high], arr[mid]);
                high--;
            }
        }
    }
};