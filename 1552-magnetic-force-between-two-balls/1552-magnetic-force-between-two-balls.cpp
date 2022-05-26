class Solution {
public:
    bool isFeasible(int mid, vector<int>&pos, int k){
        int temp = pos[0],cnt=1;
        for(int i=1; i<pos.size(); i++){
            if(pos[i]-temp>=mid)
            {
                temp = pos[i];
                cnt++;
            }
        }
        return (cnt>=k);
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int low = 1, high = *max_element(position.begin(), position.end())-position[0], res = 1;
        
        while(low<=high){
            int mid = low+ (high - low)/2;
            if(isFeasible(mid, position, m)){
                res = mid;
                low = mid+1;
            }
            else 
                high = mid-1;
        }
        return res;
    }
};