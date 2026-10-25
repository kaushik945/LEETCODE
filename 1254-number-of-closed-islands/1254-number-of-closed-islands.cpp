class Solution {
    void dfs1(int i, int j, vector<vector<int>>& vis, vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        int dr[] = {1,0,-1,0};
        int dc[] = {0,-1,0,1};
        vis[i][j] = 1;
        grid[i][j] = 1;
        for(int k = 0; k < 4; k++){
            int nr = i + dr[k];
            int nc = j + dc[k];
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] == 0){
                dfs1(nr,nc,vis,grid);
            }
        }
    }
    void dfs2(int i, int j, vector<vector<int>>& vis, vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        int dr[] = {1,0,-1,0};
        int dc[] = {0,-1,0,1};
        vis[i][j] = 1;
        for(int k = 0; k < 4; k++){
            int nr = i + dr[k];
            int nc = j + dc[k];
            if(nr >= 0 && nr < n && nc >= 0 && nr < m && !vis[nr][nc] && grid[nr][nc] == 0){
                dfs2(nr,nc,vis,grid);
            }
        }
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m));
        for (int i = 0; i < m; i++) {
            if (grid[0][i] == 0)
                dfs1(0, i, vis, grid);
            if (grid[n - 1][i] == 0)
                dfs1(n-1, i, vis, grid);
        }
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 0)
                dfs1(i, 0, vis, grid);
            if (grid[i][m - 1] == 0)
                dfs1(i, m-1, vis, grid);
        }
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && grid[i][j] == 0){
                    cnt++;
                    dfs2(i,j,vis,grid);
                }
            }
        }
        return cnt;
    }
};