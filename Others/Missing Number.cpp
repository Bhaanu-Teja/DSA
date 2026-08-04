// Brute
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xorAns1 = 0;
        for(int i = 0; i<=n; i++){
            xorAns1 = xorAns1 ^ i;
        }
        int xorAns2 = 0;
        for(int i = 0; i<n; i++){
            xorAns2 = xorAns2 ^ nums[i];
        }
        return xorAns1 ^ xorAns2;
    }
};

// Optimal
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int expectedSum = n*(n+1)/2;
        int actualSum = 0;
        for(int i = 0; i<n; i++){
            actualSum += nums[i];
        }
        return expectedSum - actualSum;
    }
};
