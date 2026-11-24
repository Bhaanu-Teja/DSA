// Brute
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i<n; i++){
            int count = 1;
            for(int j = i+1; j<n; j++){
                if(nums[j] == nums[i]){
                    count ++;
                }
            }
            if(count > n/2) return nums[i];
        }
    }
};

// Better
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for(int i = 0; i<n; i++){
            freq[nums[i]]++;
            if(freq[nums[i]] > n/2) return nums[i];
        }
        return 0;
    }
};

// Optimal
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int candidate = 0;
        int count = 0;
        for(int i = 0; i<n; i++){
            if(count == 0){
                candidate = nums[i];
            }
            if(nums[i] == candidate){
                count++;
            }
            else count--;
        }
        return candidate;
    }
};

