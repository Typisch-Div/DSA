class Solution {
    int m, n;
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};

    void dfs(vector<vector<int>>& h, vector<vector<bool>>& vis,
             int r, int c) {
        vis[r][c] = true;

        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k], nc = c + dc[k];

            if (nr < 0 || nc < 0 || nr >= m || nc >= n)
                continue;

            if (!vis[nr][nc] && h[nr][nc] >= h[r][c])
                dfs(h, vis, nr, nc);
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        vector<vector<bool>> p(m, vector<bool>(n, false));
        vector<vector<bool>> a(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            dfs(heights, p, i, 0);
            dfs(heights, a, i, n - 1);
        }

        for (int j = 0; j < n; j++) {
            dfs(heights, p, 0, j);
            dfs(heights, a, m - 1, j);
        }

        vector<vector<int>> ans;

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (p[i][j] && a[i][j])
                    ans.push_back({i, j});

        return ans;
    }
};