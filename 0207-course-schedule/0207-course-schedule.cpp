
class Solution {
public:
    bool dfs(int u, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathVis) {
        vis[u] = 1;
        pathVis[u] = 1;

        for(auto v : adj[u]) {
            if(!vis[v]) {
                if(!dfs(v, adj, vis, pathVis))
                    return false;
            }
            else if(pathVis[v]) {
                return false;
            }
        }

        pathVis[u] = 0;
        return true;
    }

    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        vector<int> vis(n, 0), pathVis(n, 0);

        for(auto &p : prerequisites) {
            adj[p[0]].push_back(p[1]);
        }

        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                if(!dfs(i, adj, vis, pathVis))
                    return false;
            }
        }

        return true;
    }
};
