// Brute Force
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>nums3;
        for(int i =0; i<nums1.size();i++){
            nums3.push_back(nums1[i]);
        }
        for(int i = 0; i< nums2.size();i++){
            nums3.push_back(nums2[i]);
        }
        sort(nums3.begin(),nums3.end());
        int n = nums3.size();
        if(n%2 == 1){
            return nums3[n/2];
        }
        else{
            return (nums3[n/2 - 1] + nums3[n/2])/2.0;
        }
        return 0;
    }
};

// Optimal
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>nums3;
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n3 = n1 + n2;
        int k = 0, j = 0;
        for(int i = 0; i<n3; i++){
            if(j >= n2){
                nums3.push_back(nums1[k]);
                k++;
            }
            else if(k >= n1){
                nums3.push_back(nums2[j]);
                j++;
            }
            else if(nums1[k] < nums2[j]){
                nums3.push_back(nums1[k]);
                k++;
            }
            else{
                nums3.push_back(nums2[j]);
                j++;
            }
        }
        int n = nums3.size();
        if (n % 2 == 1) {
            return nums3[n / 2];
        } else {
            return (nums3[n / 2 - 1] + nums3[n / 2]) / 2.0;
        }
    }
};
