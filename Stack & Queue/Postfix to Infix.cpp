class Solution {
public:
    string postToInfix(string postExp) {
        stack<string> st;

        for (int i = 0; i < (int)postExp.size(); i++) {
            char ch = postExp[i];

            if (ch >= 'a' && ch <= 'z') {
                st.push(string(1, ch));
            }
            else {
                string t1 = st.top(); st.pop(); 
                string t2 = st.top(); st.pop(); 

                st.push("(" + t2 + ch + t1 + ")");
            }
        }
        return st.top();
    }
};
