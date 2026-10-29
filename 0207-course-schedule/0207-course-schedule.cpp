
class Solution {
public:
    bool dfs(int u, vector<vector<int>>& adj, vector<int>& vis) {
        vis[u] = 1;

        for(auto v : adj[u]) {
            if(!vis[v]) {
                if(!dfs(v, adj, vis))
                    return false;
            }
            else if(vis[v] == 1) {
                return false;
            }
        }

        vis[u] = 2;
        return true;
    }

    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        vector<int> vis(n, 0);

        for(auto &p : prerequisites) {
            adj[p[0]].push_back(p[1]);
        }

        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                if(!dfs(i, adj, vis))
                    return false;
            }
        }

        return true;
    }
};
