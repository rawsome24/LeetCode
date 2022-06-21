class Solution {
public:
    int furthestBuilding(vector<int>& v, int bricks, int ladders) {
        priority_queue<int>pq;
        for(int i = 0; i<v.size()-1; i++){
            int d = v[i+1]-v[i];
            if(d>0){
                pq.push(-d);
            }
            if(pq.size()>ladders){
                int b = pq.top();
                pq.pop();
                bricks +=b;
            }
            if(bricks<0)
                return i;
        }
        return v.size()-1;
    }
};