class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (abs(target) > sum) return 0;

        int total = sum + target;
        if (total % 2 != 0) return 0;

        int goal = total / 2;
        vector<int> dp(goal + 1, 0);
        dp[0] = 1;

        for (int x : nums) {
            for (int s = goal; s >= x; s--) {
                dp[s] += dp[s - x];
            }
        }

        return dp[goal];
    }
};