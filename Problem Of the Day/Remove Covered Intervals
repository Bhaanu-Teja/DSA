// 06-07-2026
// 1288.Remove Covered Intervals -> Brute
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        int n = intervals.size();
        
        auto lambda = [] (vector<int>& vec1, vector<int>& vec2){
            if(vec1[0] == vec2[0]){
                return vec1[1]>vec2[1];
            }
            return vec1[0]<vec2[0];
        }

        sort(begin(intervals), end(intervals), lambda);
        result.push_back(intervals[0]);
        for(int i = 0; i<n; i++){
            if(result.back() [0] <= result[i][0] && result.back()[1] >= result[i][1]){
                continue;
            }
            result.push_back(intervals[i]);
        }
        return result.size()
    }
};

// Remove Covered Intervals -> Optimal
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        auto lambda = [] (vector<int>& vec1, vector<int>& vec2){
            if(vec1[0] == vec2[0]){
                return vec1[1]>vec2[1];
            }
            return vec1[0]<vec2[0];
        };

        sort(begin(intervals), end(intervals), lambda);
        int lastIntervalEnd = intervals[0][1];
        int count = 1;

        for(int i = 0; i<n; i++){
            if(lastIntervalEnd >= intervals[i][1]){
                continue;
            }
            lastIntervalEnd = intervals[i][1];
            count++;
        }
        return count;
    }
};
