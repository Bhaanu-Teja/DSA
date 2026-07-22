// Brute
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

// Optimal
class Solution {
public:
    vector<int> nextSmallerElements(const vector<int>& arr) {
        int n = arr.size();
        vector<int>ans;
        stack<int>st;
        for(int i = n-1; i>= 0; i--){
            while(!st.empty() && st.top() >= arr[i])
                st.pop();
            ans[i] = st.empty() ? -1 : st.top();
            st.push(arr[i]);
        }
        return ans;
    }
};
