// Brute
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if(s == t) return true;
        else return false;
    }
};

// Optimal
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        int count[26] = {0};
        for(char c : s) count[c - 'a']++;
        for(char c : t) count[c - 'a']--;
        for(int i = 0; i < 26; i++){
            if(count[i] != 0) return false;
        }
        return true;
    }
};
