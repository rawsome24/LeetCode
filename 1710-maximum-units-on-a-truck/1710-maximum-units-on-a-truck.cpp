class Solution {
public:
    struct cmp{
        bool operator()(vector<int>&a, vector<int>&b){
            {return a[1]>b[1];}
        }
    };
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), cmp());
        int ans = 0, i=0;
        for(i=0; i<boxTypes.size(); i++){
            if(boxTypes[i][0]<truckSize){
                ans+=(boxTypes[i][1]*boxTypes[i][0]);
                truckSize-=boxTypes[i][0];
            }
            else 
                break;
        }
        if(i<boxTypes.size())
            ans+=truckSize*boxTypes[i][1];
        return ans;
    }
};