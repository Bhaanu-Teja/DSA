// Brute
class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        for(long long i = 1; i<=x/2 + 1; i++){
            if(i*i == x) return i;
            if(i* i > x) return i-1;
        }
        return -1;
    }
};

// Optimal
class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        long long left = 1, right = x;
        while(left <= right){
            long long mid = left + (right - left)/2;
            if(mid * mid == x) return mid;
            else if(mid*mid < x) left = mid + 1;
            else right = mid - 1;
        }
        return right;
    }
};
