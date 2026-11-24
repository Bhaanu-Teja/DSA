// Brute
class Solution {
public:
    vector<int> leaders(vector<int>& nums) {
        int n = nums.size();
        vector<int>arr;
        for(int i = 0; i<n; i++){
            bool leader = true;
            for(int j = i + 1; j<n; j++){
                if(nums[j] >= nums[i]){
                    leader = false;
                    break;
                }
            }
            if(leader){
                arr.push_back(nums[i]);
            }
        }
        return arr;
    }
};

// Better
class Solution {
public:
    vector<int> leaders(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return {};
        vector<int> suffixMax(n);
        vector<int> arr;
        suffixMax[n-1] = nums[n-1];

        for(int i = n-2; i>=0; i--){
            suffixMax[i] = max(nums[i], suffixMax[i+1]);
        }
        for(int i = 0; i<n-1; i++){
            if(nums[i] >= suffixMax[i+1]){
                arr.push_back(nums[i]);
            }
        }
        arr.push_back(nums[n-1]);
        return arr;
    }
};

// Optimal
class Solution {
public:
    vector<int> leaders(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return {};
        vector<int> arr;
        int maxRight = nums[n-1];
        arr.push_back(nums[n-1]);
        for(int i = n-2; i>=0; i--){
            if(nums[i] >= maxRight){
                arr.push_back(nums[i]);
                maxRight = nums[i];
            }
        }
        reverse(arr.begin(), arr.end());
        return arr;
    }
};


