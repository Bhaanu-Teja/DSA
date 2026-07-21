class Solution {
public:
    string infixToPostfix(string s) {
        int i = 0;
        stack<char>st;
        string ans = "";

        auto precedence = [] (char op)-> int{
            if(op == '^') return 3;
            if(op == '*' || op == '/') return 2;
            if(op == '+' || op == '-') return 1;
            return 0;
        };

        while(i < s.size()){
            char ch = s[i];
            if((ch >= 'A' && ch  <= 'Z')||
              (ch >= 'a' && ch <= 'z')||
              (ch >= '0' && ch <= '9')){
                ans += ch;
              } 
              else if(ch == '('){
                st.push(ch);
              }
              else if(ch == ')'){
                while(!st.empty() && st.top() != '('){
                    ans += st.top();
                    st.pop();
                }
                st.pop();
              }
              else{
                while(!st.empty() && st.top() != '(' && (precedence(st.top()) > precedence(ch) ||
                (precedence(st.top()) == precedence(ch) && ch != '^'))){
                    ans += st.top();
                    st.pop();
                }
                st.push(ch);
              }
              i++;
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};
