class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = (int)s.size()-1;
        while(i<j){
            while(i<j && !isalnum((unsigned char)s[i])) i++;
            while(i<j && !isalnum((unsigned char) s[j])) j--;
            if(toupper((unsigned char)s[i]) != toupper((unsigned char)s[j])) return false;
            i++;
            j--;
        }
        return true;
    }
};
