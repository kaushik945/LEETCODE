class Solution {
public:
    int ind(char c) { return c; }
    int lengthOfLongestSubstring(string s) {
        vector<int> freq(256, 0);
        int i = 0, j = 0;
        int n = s.size();
        int maxlen = 0;
        while (j < n) {
            while (freq[ind(s[j])] > 0 ) {
                freq[ind(s[i])]--;
                i++;
            }
            freq[ind(s[j])]++;
            maxlen = max(j-i+1, maxlen);
            j++;
        }
        return maxlen;
    }
};