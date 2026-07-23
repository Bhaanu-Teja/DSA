class NumArray {
public:
    vector<int>pre;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        pre.assign(n+1,0);
        for(int i = 0; i<n; i++){
            pre[i+1] = pre[i] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return pre[right + 1] - pre[left];
    }
};
