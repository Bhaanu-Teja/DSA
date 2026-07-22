class Solution {
public:
    vector<int> nextSmallerElements(const vector<int>& arr) {
        int n = arr.size();
        vector<int>ans;
        for(int i = 0; i<n; i++){
            int el = arr[i];
            int nextGreater = -1;
            for(int j = i+1; j<n; j++){
                if(arr[j] < el){
                    nextGreater = arr[j];
                    break;
                }
            }
            ans.push_back(nextGreater);
        }
        return ans;
    }
};
