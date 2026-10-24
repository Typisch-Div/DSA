class Solution {
public:
    unordered_map<long long, int> cnt;

    int dfs(TreeNode* root, long long sum, int target) {
        if (!root) return 0;

        sum += root->val;

        int ans = cnt[sum - target];
        cnt[sum]++;

        ans += dfs(root->left, sum, target);
        ans += dfs(root->right, sum, target);

        cnt[sum]--;
        return ans;
    }

    int pathSum(TreeNode* root, int targetSum) {
        cnt.clear();
        cnt[0] = 1;
        return dfs(root, 0, targetSum);
    }
};