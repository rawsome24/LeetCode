class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        st.push(-1);
        int mx = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='(')
                st.push(i);
            else{
                    if(st.empty()==false)
                    st.pop();
                    if(st.empty()==true)
                        st.push(i);
                        mx = max(mx, i-(st.top()));
                }
        }
        return mx;
    }
};