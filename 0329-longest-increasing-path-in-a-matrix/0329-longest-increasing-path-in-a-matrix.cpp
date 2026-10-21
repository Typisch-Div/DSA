class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& a) {
        int m = a.size(), n = a[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int dirs[5] = {1, 0, -1, 0, 1};
        function<int(int,int)> dfs = [&](int i, int j) {
            if (dp[i][j]) return dp[i][j];
            dp[i][j] = 1;
            for (int d = 0; d < 4; d++) {
                int x = i + dirs[d], y = j + dirs[d + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && a[x][y] > a[i][j])
                    dp[i][j] = max(dp[i][j], 1 + dfs(x, y));
            }
            return dp[i][j];
        };
        int ans = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) ans = max(ans, dfs(i, j));
        return ans;
    }
};