// 07-07-2026
// 3754. Concatenate Non - Zero digits and multiply by Sum I
class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);
        string x = "";
        long long sum = 0;
        for(char c : s){
            if(c != '0'){
                x.push_back(c);
                sum += (c-'0');
            }
        }
        if(x.empty()) return 0;
        long long val = stoll(x);
        return val * sum;
    }
};
