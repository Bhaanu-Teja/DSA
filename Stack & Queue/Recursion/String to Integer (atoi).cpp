class Solution {
public:
    int myAtoi(string s) {
        long long num = 0;
        int n = (int)s.size();
        int i = 0;

        while(i < n && s[i] == ' ') i++;

        int sign = 1;
        if(i < n && (s[i] == '-' || s[i] == '+')){
            if(s[i] == '-') sign = -1;
            i++;
        }

        while(i < n){
            char c = s[i];
            if(c < '0' || c>'9') break;
            num = num * 10 + (c-'0');

            if(sign == 1 && num > INT_MAX) return INT_MAX;
            if(sign == -1 && -num < INT_MIN) return INT_MIN;
            i++;
        }
        return (int)(sign*num);
    }
};
