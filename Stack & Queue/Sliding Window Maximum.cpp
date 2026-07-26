class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>maxii;
        for(int i = 0; i<n-k+1; i++){
            int maxi = nums[i];
            for(int j = i; j < i+k; j++){
                maxi = max(maxi,nums[j]);
            }
            maxii.push_back(maxi);
        }
        return maxii;
    }
};
