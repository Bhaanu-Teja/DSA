class Solution {
public:
    string prefixToPostfix(const string& s) {
        int i = (int)s.size() - 1;
        stack<string>st;
        while(i >= 0){
            char ch = s[i];
            if((ch >= 'A' && ch  <= 'Z')||
              (ch >= 'a' && ch <= 'z')||
              (ch >= '0' && ch <= '9')){
                st.push(string(1,ch));
            }
            else{
                string t1 = st.top();
                st.pop();
                string t2 = st.top();
                st.pop();
                st.push(t1 + t2 + ch);
            }
            i--;
        }
        return st.top();
    }
};
