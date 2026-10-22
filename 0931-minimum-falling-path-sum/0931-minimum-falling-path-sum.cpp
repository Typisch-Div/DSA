class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> dp = matrix[0];

        for (int i = 1; i < n; i++) {
            vector<int> cur(n);

            for (int j = 0; j < n; j++) {
                cur[j] = matrix[i][j] + dp[j];

                if (j > 0)
                    cur[j] = min(cur[j], matrix[i][j] + dp[j - 1]);

                if (j + 1 < n)
                    cur[j] = min(cur[j], matrix[i][j] + dp[j + 1]);
            }

            dp = cur;
        }

        return *min_element(dp.begin(), dp.end());
    }
};