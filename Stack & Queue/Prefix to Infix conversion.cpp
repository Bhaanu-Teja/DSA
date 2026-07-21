class Solution {
public:
    string prefixToInfix(string s) {
        int i = (int)s.size()-1;
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
                string con = "(" + t1 + ch + t2 + ")";
                st.push(con);
            }
            i--;
        }
        return st.top();
    }
};
