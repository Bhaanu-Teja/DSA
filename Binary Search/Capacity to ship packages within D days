// // Capacity to ship packages within D days --> Brute Force
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int start = *max_element(weights.begin(),weights.end());
        int end = 0;
        for(int i = 0; i<n; i++) end += weights[i];
        for(int i = start; i<=end; i++){
            int count = 1;
            int sum = 0;
            for(int j = 0; j<n; j++){
                if(sum + weights[j] <= i){
                    sum += weights[j];
                }
                else{
                    sum = weights[j];
                    count ++;
                }
            }
            if(count <= days) return i;
        }
        return -1;
    }
};



// // Capacity to ship packages within D days --> Optimal
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = *max_element(weights.begin(),weights.end());
        int high = 0;
        for(int i = 0; i<n; i++) high += weights[i];
        while(low <= high){
            int mid = low+(high-low)/2;
            int sum = 0;
            int count = 1;
            for(int j = 0; j<n; j++){
                if(sum + weights[j] <= mid){
                    sum += weights[j];
                }
                else{
                    sum = weights[j];
                    count ++;
                }
            }
            if(count <= days) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};
