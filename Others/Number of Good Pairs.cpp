class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i<n; i++){
            int el = nums[i];
            for(int j = i+1; j<n; j++){
                if(nums[j] == el) sum++;
            }
        }
        return sum;
    }
};
