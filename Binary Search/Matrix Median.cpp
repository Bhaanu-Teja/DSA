class Solution{
public:
    int findMedian(vector<vector<int>>&matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int>output;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                output.push_back(matrix[i][j]);
            }
        }
        sort(output.begin(), output.end());
        return output[(n*m)/2];
    }
};
