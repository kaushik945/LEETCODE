
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival,
                               vector<int>& load) {
        set<int> free;
        using pii = pair<int, int>;

        priority_queue<pii, vector<pii>, greater<pii>> busy;

        vector<int> requests(k, 0);

        for (int i = 0; i < k; i++)
            free.insert(i);

        int n = arrival.size();

        for (int i = 0; i < n; i++) {
            int ar = arrival[i];

            // Release servers that have completed their requests
            while (!busy.empty() && busy.top().first <= ar) {
                auto [endTime, server] = busy.top();
                busy.pop();
                free.insert(server);
            }

            // Drop request if every server is busy
            if (free.empty())
                continue;

            // Find the next available server
            auto it = free.lower_bound(i % k);

            // Wrap around if necessary
            if (it == free.end())
                it = free.begin();

            int server = *it;

            requests[server]++;
            busy.push({ar + load[i], server});
            free.erase(it);
        }

        int mx = *max_element(requests.begin(), requests.end());

        vector<int> ans;
        for (int i = 0; i < k; i++) {
            if (requests[i] == mx)
                ans.push_back(i);
        }

        return ans;
    }
};
