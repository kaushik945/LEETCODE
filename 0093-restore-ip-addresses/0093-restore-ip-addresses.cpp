class Solution {
    vector<string> ans;

public:
    void func(int i, int cnt, string& s, string temp) {
        int n = s.size();

        // Used all 4 segments
        if (cnt == 0) {
            if (i == n) {
                temp.pop_back(); // remove last dot
                ans.push_back(temp);
            }
            return;
        }

        if (i >= n) return;

        // Take 1 digit
        temp += s[i];
        temp += '.';
        func(i + 1, cnt - 1, s, temp);
        temp.pop_back();
        temp.pop_back();

        // Take 2 digits
        if (i + 1 < n && s[i] != '0') {
            temp += s[i];
            temp += s[i + 1];
            temp += '.';

            func(i + 2, cnt - 1, s, temp);

            for (int j = 0; j < 3; j++)
                temp.pop_back();
        }

        // Take 3 digits
        if (i + 2 < n && s[i] != '0') {
            int x = stoi(s.substr(i, 3));

            if (x <= 255) {
                temp += s[i];
                temp += s[i + 1];
                temp += s[i + 2];
                temp += '.';

                func(i + 3, cnt - 1, s, temp);

                for (int j = 0; j < 4; j++)
                    temp.pop_back();
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        ans.clear();

        int n = s.size();
        if (n < 4 || n > 12) return {};

        func(0, 4, s, "");

        return ans;
    }
};