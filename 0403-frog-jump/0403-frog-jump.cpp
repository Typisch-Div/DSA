class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        unordered_map<int, unordered_set<int>> dp;

        for (int x : stones)
            dp[x] = {};

        dp[0].insert(0);

        for (int x : stones) {
            for (int k : dp[x]) {
                for (int step = k - 1; step <= k + 1; step++) {
                    if (step <= 0) continue;

                    int next = x + step;

                    if (dp.count(next))
                        dp[next].insert(step);
                }
            }
        }

        return !dp[stones.back()].empty();
    }
};