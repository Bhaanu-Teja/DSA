// Brute
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        for(int i = 0; i<n; i++){
            int el = nums[i];
            bool found = false;

            for(int j = i+1; j < n; j++){
                if(nums[j] > el){
                    ans.push_back(nums[j]);
                    found = true;
                    break;
                }
            }
            if(!found){
                for(int j = 0; j<i; j++){
                    if(nums[j] > el){
                        ans.push_back(nums[j]);
                        found = true;
                        break;
                    }
                }
            }
            if(!found){
                ans.push_back(-1);
            }
        }
        return ans;
    }
};
