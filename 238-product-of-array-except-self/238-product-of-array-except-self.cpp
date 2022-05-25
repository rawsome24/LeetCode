class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {
        vector<int>pre(arr.size());
        vector<int>post(arr.size());
        
        pre[0] = 1;
        for(int i=1; i<arr.size(); i++)
            pre[i] = arr[i-1]*pre[i-1];
        post[arr.size()-1]=1;
        for(int i=arr.size()-2; i>=0; i--)
            post[i] = post[i+1]*arr[i+1];
        
        for(int i=0; i<arr.size(); i++)
            arr[i] = post[i]*pre[i];
        return arr;
    }
};