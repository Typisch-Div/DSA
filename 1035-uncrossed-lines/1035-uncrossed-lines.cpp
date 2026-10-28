class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= m; i++) {
            vector<int> cur(n + 1, 0);

            for (int j = 1; j <= n; j++) {
                if (nums1[i - 1] == nums2[j - 1])
                    cur[j] = dp[j - 1] + 1;
                else
                    cur[j] = max(dp[j], cur[j - 1]);
            }

            dp = cur;
        }

        return dp[n];
    }
};