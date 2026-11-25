// Brute (leetcode)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>arr;
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                if(nums[i] + nums[j] == target){
                    arr.push_back(i);
                    arr.push_back(j);
                }
            }
        }
        return arr;
    }
};

// Optimal
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int,int>mpp;
        for(int i = 0; i<n; i++){
            int num = nums[i];
            int moreNeeded = target - num;
            if(mpp.find(moreNeeded) != mpp.end()){
                return {mpp[moreNeeded],i};
            }
            mpp[num] = i;
        }
        return {-1,-1};
    }
};
