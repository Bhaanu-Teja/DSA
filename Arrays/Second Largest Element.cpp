class Solution {
public:
    int secondLargestElement(vector<int>& nums) {
        int largest = nums[0];
        int sec_largest = -1;
        for(int i = 1; i<nums.size(); i++){
            if(nums[i] > largest){
                sec_largest = largest;
                largest = nums[i];
            }
            else if(nums[i] > sec_largest && nums[i] < largest) sec_largest = nums[i];
        }
        return sec_largest;
    }
};
