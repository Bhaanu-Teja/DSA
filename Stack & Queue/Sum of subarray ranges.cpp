// Brute
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        for(int i =0; i<n; i++){
            int largest = nums[i];
            int smallest = nums[i];
            for(int j = i+1; j<n; j++){
                largest = max(largest, nums[j]);
                smallest = min(smallest, nums[j]);
                sum = sum + (long long)(largest - smallest);
            }
        }
        return sum;
    }
};

// Optimal
class Solution {
public:

    vector<int>findNSE(vector<int>&nums){
        int n = nums.size();
        vector<int>NSE(n);
        stack<int>st;
        for(int i = n-1; i>=0; i--){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            NSE[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return NSE;
    }

    vector<int>findPSE(vector<int>&nums){
        int n = nums.size();
        vector<int>PSE(n);
        stack<int>st;
        for(int i = 0; i<n; i++){
            while(!st.empty() && nums[st.top()] > nums[i])
                st.pop();
            PSE[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return PSE;
    }

    vector<int>findNLE(vector<int>&nums){
        int n = nums.size();
        vector<int> NLE(n);
        stack<int>st;
        for(int i = n-1; i>= 0; i--){
            while(!st.empty() && nums[st.top()] <= nums[i]){
                st.pop();
            }
            NLE[i] = st.empty() ?n : st.top();
            st.push(i);
        }
        return NLE;
    }

    vector<int>findPLE(vector<int>&nums){
        int n = nums.size();
        vector<int> PLE(n);
        stack<int>st;
        for(int i = 0; i<n; i++){
            while(!st.empty() && nums[st.top()] < nums[i]){
                st.pop();
            }
            PLE[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return PLE;
    }

    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> NSE = findNSE(nums);
        vector<int> PSE = findPSE(nums);

        vector<int> NLE = findNLE(nums);
        vector<int> PLE = findPLE(nums);
        long long minSum = 0;
        for(int i = 0; i<n; i++){
            long long left = i - (long long)PSE[i];
            long long right = (long long)NSE[i] - i;
            minSum += left*right*1LL*nums[i];
        }

        long long maxSum = 0;
        for(int i = 0; i<n; i++){
            long long left = i-(long long)PLE[i];
            long long right = (long long)NLE[i]-i;
            maxSum += left * right * 1LL * nums[i];
        }
        return maxSum - minSum;
    }
};
