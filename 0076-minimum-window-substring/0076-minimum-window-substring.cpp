class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> need(256, 0), window(256, 0);

        for (char c : t)
            need[c]++;

        int left = 0;
        int matched = 0;

        int minLen = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.size(); right++) {

            window[s[right]]++;

            if (need[s[right]] > 0 &&
                window[s[right]] <= need[s[right]])
                matched++;

            while (matched == t.size()) {

                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                window[s[left]]--;

                if (need[s[left]] > 0 &&
                    window[s[left]] < need[s[left]])
                    matched--;

                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};