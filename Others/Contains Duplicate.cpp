// Brute
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i<n; i++){
            int el = nums[i];
            for(int j = i+1; j<n; j++){
                if(nums[j] == el) return true;
            }
        }
        return false;
    }
};

// Optimal
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            int el = nums[i];
            if(seen.find(el) != seen.end()){
                return true;
            }
            else{
                seen.insert(el);
            }
        }
        return false;
    }
};
