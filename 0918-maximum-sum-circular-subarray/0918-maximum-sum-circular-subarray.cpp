class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0;
        int maxCur = 0, maxSum = nums[0];
        int minCur = 0, minSum = nums[0];

        for (int x : nums) {
            maxCur = max(x, maxCur + x);
            maxSum = max(maxSum, maxCur);

            minCur = min(x, minCur + x);
            minSum = min(minSum, minCur);

            total += x;
        }

        if (maxSum < 0) return maxSum;

        return max(maxSum, total - minSum);
    }
};