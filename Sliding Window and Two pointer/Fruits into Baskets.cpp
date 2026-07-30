// Brute
class Solution{
  public:
    int totalFruits(vector<int>& fruits){
        int n = fruits.size();
        int maxLen = 0;
        for(int i=0; i<n; i++){
            set<int>st;
            for(int j = i; j<n; j++){
                st.insert(fruits[j]);
                if(st.size() <= 2){
                    maxLen = max(maxLen, j-i+1);
                }
                else break;
            }
        }
        return maxLen;
    }
};

// Optimal
class Solution{
  public:
    int totalFruits(vector<int>& fruits){
        int n = fruits.size();
        int l = 0, r = 0, maxLen = 0;
        int k = 2;
        map<int,int>mpp;
        while(r < n){
            mpp[fruits[r]]++;
            if(mpp.size() > k){
                mpp[fruits[l]]--;
                if(mpp[fruits[l]] == 0) mpp.erase(fruits[l]);
                l++;
            }
            if(mpp.size() <= k) maxLen = max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }
};
