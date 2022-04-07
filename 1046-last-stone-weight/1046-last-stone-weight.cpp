class Solution {
public:
    int lastStoneWeight(vector<int>& st) {
        priority_queue<int>pq(st.begin(),st.end());
        
        while(pq.size()>1)
        {
            int f = pq.top();
            pq.pop();
            int s = pq.top();
            pq.pop();
            
            if(f-s>0)pq.push(f-s);
            
        }
        if(pq.empty()==true)return 0;
        else return pq.top();
    }
};