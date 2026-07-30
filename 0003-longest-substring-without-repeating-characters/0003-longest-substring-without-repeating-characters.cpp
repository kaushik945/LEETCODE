class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(256, -1);

        int ans = 0;
        int i = 0;

        for (int j = 0; j < s.size(); j++) {
            i = max(i, last[(unsigned char)s[j]] + 1);
            last[(unsigned char)s[j]] = j;
            ans = max(ans, j - i + 1);
        }

        return ans;
    }
};