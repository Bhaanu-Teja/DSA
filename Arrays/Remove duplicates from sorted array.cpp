// Brute Force Approach
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>temp;
        for(int i = 0; i<nums.size(); i++){
            bool found = false;
            for(int j = 0; j<temp.size(); j++){
                if(nums[i] == temp[j]){
                    found = true;
                    break;
                }
            }
            if(!found){
                temp.push_back(nums[i]);
            }
        }
        for(int i = 0; i<temp.size(); i++){
            nums[i] = temp[i];
        }
        return temp.size();
    }
};

// Better
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>temp;
        temp.push_back(nums[0]);
        for(int i = 1; i<nums.size(); i++){
            if(nums[i] != nums[i-1]){
                temp.push_back(nums[i]);
            }
        }
        for(int i = 0; i<temp.size(); i++){
            nums[i] = temp[i];
        }
        return temp.size();
    }
};


// Optimal
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int temp1 = 0;
        for(int i = 1; i<nums.size(); i++){
            if(nums[i] != nums[temp1]){
                temp1++;
                nums[temp1] = nums[i];
            }
        }
        return temp1 + 1;
    }
};
