class Solution {
public:
    // string to_bit(int i, int k){
    //     string ans = "";
    //     while(i>0){
    //         ans.push_back((i%2)+'0');
    //         i/=2;
    //     }
    //     reverse(ans.begin(), ans.end());
    //     if(ans.size()<k){
    //         while(ans.size()<k)
    //             ans.append("0");
    //     }
    //     return ans;
    // }
    bool hasAllCodes(string s, int k) {
        int i=0, j=0;
        string num="";
        unordered_set<int>st;
        while(j<s.length()){
            num.push_back(s[j]);
            
            if(num.size()<k)
                j++;
            
            else if(num.size()==k){
                unsigned long decimal = bitset<32>(num).to_ulong();
                st.insert(decimal);
                num.erase(num.begin()+0);
                i++;
                j++;
            }
        }
        for(int i=0; i<pow(2,k); i++)
        {
            if(st.find(i)==st.end())
                return false;
        }
        return true;
    }
};