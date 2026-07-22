// Brute
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        for(int i = 0; i<nums1.size(); i++){
            int el = nums1[i];
            int foundIndex = -1;
            for(int j = 0; j<nums2.size(); j++){
                if(nums2[j] == el){
                    foundIndex = j;
                    break;
                }
            }
            int nextGreater = -1;
            for(int l = foundIndex+1; l<nums2.size(); l++){
                if(nums2[l] > el){
                    nextGreater = nums2[l];
                    break;
                }
            }
            ans.push_back(nextGreater);
        }
        return ans;
    }
};

// Optimal
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>nextGreater;
        stack<int>st;
        for(int i=0; i<nums2.size();i++){
            int x = nums2[i];
            while(!st.empty() && st.top() < x){
                 nextGreater[st.top()] = x;
                st.pop();
            }
            st.push(x);
        }
        while(!st.empty()){
        nextGreater[st.top()] = -1;
        st.pop();
        }
        vector<int>ans;
        ans.reserve(nums1.size());
        for(int i = 0; i<nums1.size(); i++){
            int x = nums1[i];
            ans.push_back(nextGreater[x]);
        }
        return ans;
    }
};
