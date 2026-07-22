class Solution {
public:
    vector<int> count_NGE(vector<int> &arr, vector<int> &indices) {
        int n = arr.size();
        vector<int>ans;
        ans.reserve(indices.size());

        for(int idx : indices){
            int cnt = 0;
            for(int j = idx + 1; j<n; j++){
                if(arr[j] > arr[idx]) cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
