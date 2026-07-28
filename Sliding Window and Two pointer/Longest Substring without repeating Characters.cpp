class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxLen = 0;
        for(int i = 0; i<n; i++){
            int hash[256] = {0};
            for(int j = i; j<n; j++){
                if(hash[s[j]] == 1) break;
                int len = j-i+1;
                maxLen = max(len, maxLen);
                hash[s[j]] = 1;
            }
        }
        return maxLen;
    }
};

// Optimal
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int hash[256];
        memset(hash, -1, sizeof(hash));
        int l = 0, r=0, maxLen = 0;
        while(r < n){
            if(hash[s[r]] != -1){
                if(hash[s[r]] >= l){
                    l = hash[s[r]]+1;
                }
            }
            int len = r-l+1;
            maxLen = max(maxLen, len);
            hash[s[r]] = r;
            r++;
        }
        return maxLen;
    }
};
