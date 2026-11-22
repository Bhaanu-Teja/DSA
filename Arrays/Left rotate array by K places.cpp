class Solution {
public:
    void rotateArray(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        vector<int> arr(k);
        for(int i = 0; i<k; i++){
            arr[i] = nums[i];
        }
        for(int i = 0; i<n-k; i++){
            nums[i] = nums[i+k];
        }
        int j = 0;
        for(int i = n-k; i<n; i++){
            nums[i] = arr[j++];
        }
    }
};
