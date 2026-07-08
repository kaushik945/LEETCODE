class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;

        int ans = 0;

        for (int i = 0; i < n; i++) {
            map<pair<int, int>, int> mp;
            int duplicate = 1;

            for (int j = i + 1; j < n; j++) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                // Duplicate point
                if (dx == 0 && dy == 0) {
                    duplicate++;
                    continue;
                }

                int g = gcd(abs(dx), abs(dy));
                dx /= g;
                dy /= g;

                // Normalize sign
                if (dx < 0) {
                    dx *= -1;
                    dy *= -1;
                }

                // Vertical line
                if (dx == 0)
                    dy = 1;

                // Horizontal line
                if (dy == 0)
                    dx = 1;

                mp[{dx, dy}]++;
            }

            ans = max(ans, duplicate);

            for (auto &it : mp)
                ans = max(ans, it.second + duplicate);
        }

        return ans;
    }
};