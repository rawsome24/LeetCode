// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string smallestNumber(int S, int D){
        // code here 
        if(D*9<S)return "-1";
        if(D==1)return to_string(S);
        
        if(S<10)
        {
            string str="";
            str.push_back('1');
            S = S-1;
            for(int i=0; i<D-2; i++)
                str.push_back('0');
            str.push_back(S+'0');
            return str;
        }
        else 
        {
            string str = "";
            int i=0;
            bool flag = false;
            for(i=0; i<D-1; i++)
            {
                if(S>9)str.push_back('9');
                else {
                    str.push_back(S-1+'0');
                    flag = true;
                    break;
                }
                S = S-(str[i]-'0');
            }
            for(int j=i+1; j<D-1; j++)
                str.push_back('0');
            if(flag)str.push_back('1');
            else str.push_back(S+'0');
            reverse(str.begin(), str.end());
            return str;
        }
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.smallestNumber(S,D) << endl;
    }
    return 0; 
}   // } Driver Code Ends