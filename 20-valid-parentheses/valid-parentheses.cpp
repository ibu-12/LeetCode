class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int l = s.length();
        st.push(s[0]);
        string str = "";
        for (int i = 1; i < l; i++) {
            if (!st.empty() && ((st.top()=='('&&s[i]==')')||(st.top()=='{'&&s[i]=='}')|| (st.top()=='['&&s[i]==']'))) {
                st.pop();
                continue;
            }
            st.push(s[i]);
        }
        
        return st.empty();
    }
};