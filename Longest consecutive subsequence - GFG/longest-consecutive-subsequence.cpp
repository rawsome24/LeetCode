// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
        int h[100001]={0};
        for(int i=0; i<N; i++){
            h[arr[i]]++;
        }
        int cnt=1, ans = INT_MIN;
        for(auto it=0; it<100001; it++){
            if(h[it]>=1 && h[it+1]>=1)
            {
                cnt++;
                ans = max(ans, cnt);
            }
            else cnt=1;
        }
        if(ans==INT_MIN)return 1;
        else return ans;
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends