class Solution {
public:
    string decodeString(string s) {
        stack<char>st;
        int i = 0;
        int open  = 0;
        string ans = "";
        while(i<s.length()){
            if(s[i]!=']')
                st.push(s[i]);
            else {
                string tmp="";
                while(st.empty()==false and st.top()!='['){
                    tmp = st.top()+tmp;
                    st.pop();
                }
                st.pop();
                string num="";
                while(st.empty()==false and isdigit(st.top())){
                    num = st.top()+num;
                    st.pop();
                }
                int k = stoi(num);
                while(k--){
                    for(int i=0; i<tmp.size(); i++){
                        st.push(tmp[i]);
                    }
                }
            }
            i++;
        }
        while(st.empty()==false){
            ans =st.top()+ans;
            st.pop();
        }
        
        return ans;
    }
};