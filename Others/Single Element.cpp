class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorAns = 0;
        for(int i = 0; i<nums.size(); i++){
            xorAns = xorAns ^ nums[i];
        }
        return xorAns;
    }
};
