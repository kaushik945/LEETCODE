class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int mod = 1e9 + 7;

        long long even = 1; // Empty prefix has an even sum
        long long odd = 0;
        long long ans = 0;
        int parity = 0;

        for (int x : arr) {
            parity ^= (x % 2);

            if (parity == 1) {
                ans = (ans + even) % mod;
                odd++;
            } else {
                ans = (ans + odd) % mod;
                even++;
            }
        }

        return ans;
    }
};