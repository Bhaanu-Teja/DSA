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

// Optimal
class Solution {
public:
    vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int>arr;
        int t1 = 0;
        int t2 = 0;
        while(t1 < n && t2 < m){
            if(nums1[t1] < nums2[t2]){
                if(arr.empty() || arr.back() != nums1[t1])
                    arr.push_back(nums1[t1]);
                t1++:
            }
            else if(nums2[t2] < nums1[t1]){
                if(arr.empty() || arr.back() != nums2[t2])
                    arr.push_back(nums2[t2]);
                t2++:
            }
            else{
                if(arr.empty() || arr.back() != nums2[t2])
                    arr.push_back(nums1[t1]);
                t1++;
                t2++:
            }
        }
        while(t1 <n){
            if(arr.empty() || arr.back() != nums1[t1])
                arr.push_back(nums1[t1]);
            t1++;
        }
        while(t2 < m){
            if(arr.empty() || arr.back() != nums2[t2])
                arr.push_back(nums2[t2]);
            t2++;
        }
        return arr;
    }
};

