class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0;
        int maxlen = 0;
        set<char> st;

        for(int r = 0; r < n; r++) {
            while(st.find(s[r]) != st.end()) {
                st.erase(s[l]);
                l++;
            }

            st.insert(s[r]);
            maxlen = max(maxlen, r - l + 1);
        }

        return maxlen;
    }
};