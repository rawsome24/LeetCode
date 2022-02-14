class Solution {
public:
    string addBinary(string a, string b) {
        int carry=0;
        string ans;
        if(a.length()!=b.length())
        {
            if(a.length()>b.length())
            {
                while(a.length()-b.length())
                    b.insert(0,"0");
            }
            else{
                while(b.length()-a.length())
                    a.insert(0,"0");
            }
            
        }
        if(a.length()==b.length()){
            for(int i=a.length()-1; i>=0; i--)
            {
                int k = a[i]-'0'+b[i]-'0';
                if(carry){k=k+carry;}
                carry = k>=2?1:0;
                ans.push_back(k%2+'0');
            }
            if(carry)ans.push_back('1');
            reverse(ans.begin(),ans.end());
            return ans;
        }
        return ans;
    }
};