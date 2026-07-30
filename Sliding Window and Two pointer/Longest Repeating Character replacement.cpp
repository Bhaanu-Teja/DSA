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

// Optimal
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0, r = 0, maxLen = 0, maxFreq = 0;
        int hash[26] = {0};
        for(int r = 0; r< s.size(); r++){
            hash[s[r] - 'A']++;
            maxFreq = max(maxFreq, hash[s[r] - 'A']);
            while((r-l+1) - maxFreq > k){
                hash[s[l] - 'A']--;
                l++;
            }
            maxLen = max(maxLen, r-l+1);
        }
        return maxLen;
    }
};
