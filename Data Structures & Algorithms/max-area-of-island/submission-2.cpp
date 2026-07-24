class Solution {
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, -1, 0, 1};
    int dfs(vector<vector<int>>& vis, vector<vector<int>>& grid, int r, int c) {
        vis[r][c] = 1;
        int area = 1;
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() && vis[nr][nc] == 0 &&
                grid[nr][nc] == 1) {
                area += dfs(vis, grid, nr, nc);
            }
        }
        return area;
    }

   public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] == 0 && grid[i][j] == 1) {
                    int temp = dfs(vis, grid, i, j);
                    ans = max(ans, temp);
                }
            }
        }
        return ans;
    }
};

