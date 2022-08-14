class Solution {
public:
    int edgeScore(vector<int>& edges) {
        map<int,vector<int>>mp;
        for(int i=0; i<edges.size(); i++){
            mp[edges[i]].push_back(i);
        }
        long long sum = 0;
        int ind = INT_MAX;
        for(auto it=mp.begin(); it!=mp.end(); it++){
            long long tempSum = 0;
            for(int i=0; i<it->second.size(); i++){
                tempSum+=it->second[i];
            }
            if(tempSum>sum){
                ind = it->first;
                cout<<ind<<endl;
                sum = tempSum;
            }
        }
        return ind;
    }
};