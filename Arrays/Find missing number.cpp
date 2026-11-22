class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i<n; i++){
            if(nums[i] != i) return i;
        }
        return n;
    }
};

// Optimal
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int total = n * (n+1)/2;
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum += nums[i];
        }
        return total - sum;
    }
};

