#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
typedef tree<int, null_type, std::less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    oset;

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        oset free;
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