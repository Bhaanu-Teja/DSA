class Solution {
public:
    string infixToPrefix(const string& s) {
        auto prec = [&](char op) {
            if (op == '+' || op == '-') return 1;
            if (op == '*' || op == '/') return 2;
            return 0;
        };

        string rev = s;
        reverse(rev.begin(), rev.end());
        for (char &ch : rev) {
            if (ch == '(') ch = ')';
            else if (ch == ')') ch = '(';
        }

        stack<char> st;
        string pref;

        for (int i = 0; i < (int)rev.size(); i++) {
            char ch = rev[i];

            if (ch >= 'a' && ch <= 'z') {
                pref.push_back(ch);
            } else if (ch == '(') {
                st.push(ch);
            } else if (ch == ')') {
                while (!st.empty() && st.top() != '(') {
                    pref.push_back(st.top());
                    st.pop();
                }
                if (!st.empty()) st.pop(); 
            } else { 
                while (!st.empty() && prec(st.top()) >= prec(ch)) {
                    pref.push_back(st.top());
                    st.pop();
                }
                st.push(ch);
            }
        }

        while (!st.empty()) {
            pref.push_back(st.top());
            st.pop();
        }

        reverse(pref.begin(), pref.end());
        return pref;
    }
};
