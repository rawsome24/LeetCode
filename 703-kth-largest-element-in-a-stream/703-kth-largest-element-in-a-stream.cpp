class KthLargest {
public:
    priority_queue<int , vector<int>, greater<int>>pq;
    int sz;
    KthLargest(int k, vector<int>& nums) {
        sz = k;
        for(int i=0; i<nums.size(); i++){
            pq.push(nums[i]);
            if(pq.size()>k)
                pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>sz){
            pq.pop();
        }
        int ans = pq.top();
        return ans;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */