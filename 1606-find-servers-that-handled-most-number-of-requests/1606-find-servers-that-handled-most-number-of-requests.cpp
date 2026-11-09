
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> free;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            busy;
        vector<int> requests(k);
        int n = load.size();
        for (int i = 0; i < k; i++)
            free.insert(i);
        for (int i = 0; i < n; i++) {
            int ar = arrival[i];
            int ld = load[i];
            while (!busy.empty() && busy.top().first <= ar) {
                auto [t, idx] = busy.top();
                busy.pop();
                free.insert(idx);
            }
            auto it = free.lower_bound(i % k);
            if (it == free.end() && !free.empty()) {
                requests[*free.begin()]++;
                busy.push({ar + ld, *free.begin()});
                free.erase(free.begin());

            } else if (it != free.end()) {
                requests[*it]++;
                busy.push({ar + ld, *it});
                free.erase(it);
            }
        }
        int ans = *ranges::max_element(requests);
        vector<int> ids;
        for (int i = 0; i < k; i++) {
            if (ans == requests[i])
                ids.push_back(i);
        }
        return ids;
    }
};