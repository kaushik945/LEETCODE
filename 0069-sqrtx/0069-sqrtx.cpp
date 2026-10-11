class Solution {
public:
    int mySqrt(int x) {
        long long int start = 0, end = x;
        long long int ans = 0;

        while (start <= end) {
            long long int mid = start + (end - start) / 2;

            if (mid * mid == x) {
                return mid;
            }
            if (mid * mid < x) {
                ans = mid; // store the candidate and search right
                start = mid + 1;
            } else {
                end = mid - 1; // search left
            }
        }
        return ans;
    }
};