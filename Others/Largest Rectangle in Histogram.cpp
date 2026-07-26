class Solution {
public:

    vector<int>findNSE(vector<int>&heights){
        int n = heights.size();
        vector<int>NSE(n);
        stack<int>st;
        for(int i = n-1; i>=0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            NSE[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return NSE;
    }

    vector<int>findPSE(vector<int>&heights){
        int n = heights.size();
        vector<int>PSE(n);
        stack<int>st;
        for(int i = 0; i<n; i++){
            while(!st.empty() && heights[st.top()] > heights[i])
                st.pop();
            PSE[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return PSE;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nse = findNSE(heights);
        vector<int> pse = findPSE(heights);
        int maxi = 0;
        for(int i = 0; i<n; i++){
            maxi = max(maxi, heights[i]*(nse[i]-pse[i]-1));
        }
        return maxi;
    }
};
