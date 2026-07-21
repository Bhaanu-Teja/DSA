class Solution {
public:
    string postToPre(string postfix) {
        stack<string> st;

        for (int i = 0; i < (int)postfix.size(); i++) {
            char ch = postfix[i];

            if (ch >= 'a' && ch <= 'z') {
                st.push(string(1, ch));
            }
            else {
                string t1 = st.top(); st.pop(); 
                string t2 = st.top(); st.pop(); 

                st.push(string(1, ch) + t2 + t1);
            }
        }
        return st.top();
    }
};
