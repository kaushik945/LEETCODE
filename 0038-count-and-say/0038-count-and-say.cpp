class Solution {
public:
    string build(string s) {
        int n = s.size();
        string new_s = "";

        int cnt = 1;

        for (int i = 1; i < n; i++) {

            if (s[i] == s[i - 1]) {
                cnt++;
            } 
            else {
                new_s += to_string(cnt);
                new_s += s[i - 1];

                cnt = 1;
            }
        }

        // handle last group
        new_s += to_string(cnt);
        new_s += s[n - 1];

        return new_s;
    }

    string solve(int i, int n, string s) {
        if (i == n)
            return s;

        return solve(i + 1, n, build(s));
    }

    string countAndSay(int n) {
        return solve(1, n, "1");
    }
};