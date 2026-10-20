class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> st;
        for (auto s : wordList) {
            st.insert(s);
        }
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        while (!q.empty()) {
            auto [w, l] = q.front();
            q.pop();
            if (w == endWord) {
                return l;
            }
            for (int i = 0; i < w.size(); i++) {
                char og = w[i];
                for (int j = 0; j < 26; j++) {
                    w[i] = 'a' +  j;
                    if (st.find(w) != st.end()) {
                        q.push({w, l + 1});
                        st.erase(w);
                    }
                }
                w[i] = og;
            }
        }
        return 0;
    }
};