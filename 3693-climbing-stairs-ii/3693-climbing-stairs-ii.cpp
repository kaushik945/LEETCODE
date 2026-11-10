
class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1, INT_MAX);
        dp[n] = 0;

        for (int i = n - 1; i >= 0; i--) {
            for (int jump = 1; jump <= 3; jump++) {
                if (i + jump <= n) {
                    dp[i] = min(dp[i],
                        costs[i + jump - 1] +
                        jump * jump +
                        dp[i + jump]);
                }
            }
        }

        return dp[0];
    }
};
