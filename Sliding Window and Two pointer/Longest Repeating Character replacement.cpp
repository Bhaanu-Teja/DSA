class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int maxLen = 0;
        for(int i = 0; i<n; i++){
            int hash[26] = {0};
            int maxFreq = 0;
            for(int j = i; j<n; j++){
                int idx = s[j]-'A';
                hash[idx]++;
                maxFreq = max(maxFreq, hash[idx]);
                int changes = (j - i + 1) - maxFreq;
                if(changes <= k)
                    maxLen = max(maxLen, j - i + 1);
            }
        }
        return maxLen;
    }
};
