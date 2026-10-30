class Solution {
public:
    int func(int i, vector<int>& nums, int n, vector<int>& dp) {
        if (i >= n) {
            return 0;
        }
        if (dp[i] != -1)
            return dp[i];
        int take = nums[i] + func(i + 2, nums, n, dp);
        int nottake = func(i + 1, nums, n, dp);
        dp[i] = max(take, nottake);
        return max(take, nottake);
    }
    int rob(vector<int>& nums) {

        int n = nums.size();
        // int ans = func(0,nums,n,dp);
        // return ans;
        // tabulation -> so
        if(n == 1) return nums[0];
        int next = 0, nextnext = 0, curr = 0;
        for (int i = n - 1; i > 0; i--) { // left 1
            int take = nums[i] + nextnext;
            int nottake = next;
            curr = max(take, nottake);
            nextnext = next;
            next = curr;
        }
        int ans1 = next;
        next = 0; nextnext=0;curr = 0;
        for (int i = n - 2; i >= 0; i--) { // left n
            int take = nums[i] + nextnext;
            int nottake = next;
            curr = max(take, nottake);
            nextnext = next;
            next = curr;
        }
        int ans2 = next;

        return max(ans1,ans2);
    }
};