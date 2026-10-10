class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1,
                               vector<int>& nums2,
                               int k1, int k2) {

        int n = nums1.size();
        vector<long long> diff(n);

        long long k = 1LL * k1 + k2;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
        }

        ranges::sort(diff);

        for (int i = n - 1; i >= 0; i--) {

            long long curr = diff[i];
            long long next = (i > 0 ? diff[i - 1] : 0);

            long long count = n - i;
            long long need = (curr - next) * count;

            if (k >= need) {
                k -= need;
            }
            else {
                long long dec = k / count;
                long long rem = k % count;

                long long level = curr - dec;

                long long ans = 0;

                for (int j = 0; j < i; j++)
                    ans += diff[j] * diff[j];

                ans += (count - rem) * level * level;
                ans += rem * (level - 1) * (level - 1);

                return ans;
            }
        }

        return 0;
    }
};