class Solution {
public:
    double findMaxAverage(vector<int>& arr, int k) {
        int i=0,j=0;
        double sum=0.000000,mx = INT_MIN;
        
        while(j<arr.size())
        {
            sum+=arr[j];
            
            if(j-i+1<k)j++;
            
            else if(j-i+1==k)
            {
                mx = max(mx, sum); 
                sum -=arr[i];
                i++; j++;
            }
        }
        return mx/k;
    }
};