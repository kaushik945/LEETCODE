
class Solution {
public:
    int func(int i, int buy, int cnt, int n,
             vector<int>& prices,
             vector<vector<vector<int>>>& dp) {

        if (i >= n || cnt == 2) {
            return 0;
        }

        if (dp[i][buy][cnt] != -1) {
            return dp[i][buy][cnt];
        }

        int profit = 0;

        if (buy) {
            profit = max(
                func(i + 1, 1, cnt, n, prices, dp),
                -prices[i] + func(i + 1, 0, cnt, n, prices, dp)
            );
        } else {
            profit = max(
                func(i + 1, 0, cnt, n, prices, dp),
                prices[i] + func(i + 1, 1, cnt + 1, n, prices, dp)
            );
        }

        return dp[i][buy][cnt] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(2, vector<int>(2, -1))
        );

        return func(0, 1, 0, n, prices, dp);
    }
};
