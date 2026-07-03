class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if((long long) m*k > n){
            return -1;
        }
        int low = *min_element(bloomDay.begin(),bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
                int bouquets = 0,marked = 0; 
                for(int j = 0; j<n; j++){ 
                    if(bloomDay[j] <= mid){ 
                        marked++; 
                        if(marked == k){ 
                            bouquets++; 
                            marked = 0; 
                        } 
                    } 
                    else{ 
                        marked = 0; 
                    } 
                } 
                if(bouquets >= m){
                    ans = mid;
                    high = mid - 1;
                } 
                else{
                    low = mid + 1;
                }
        }
        return ans;
    }
};
