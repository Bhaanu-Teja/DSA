class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        vector<int>output;
        for(int i = 0; i<n; i++){
            sum += nums[i];
            output.push_back(sum);
        }
        return output;
    }
};
