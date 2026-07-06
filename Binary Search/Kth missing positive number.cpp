// Brute Force
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int maxVal = arr.back();
        int target = maxVal + k;
        int count = 0;
        for(int i = 1; i<=target; i++){
            bool found = false;
            for(int j = 0; j<n; j++){
                if(arr[j] == i){
                    found = true;
                    break;
                }
            }
            if(!found){
                count ++;
                if(count == k) return i;
            }
        }
        return -1;
    }
};

// Optimal --> Linear Search
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        for(int i = 0; i<n; i++){
            if(arr[i] <= k) k++;
            else break;
        }
        return k;
    }
};

// Optimal --> Binary Search 
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 0, high = n-1;
        while(low <= high){
            int mid = low+(high-low)/2;
            int missing = arr[mid] - (mid + 1);
            if(missing < k) low = mid + 1;
            else high = mid - 1;
        }
        return k + high + 1;
    }
};
