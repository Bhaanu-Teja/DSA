class Solution {
public:
    vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
        for(int i = 0; i<nums2.size(); i++){
            nums1.push_back(nums2[i]);
        }
        sort(nums1.begin(), nums1.end());
        int temp1 = 0;
        for(int i = 1; i<nums1.size(); i++){
            if(nums1[i] != nums1[temp1]){
                temp1++;
                nums1[temp1] = nums1[i];
            }
        }
        nums1.resize(temp1 + 1);
        return nums1;
    }
};  
