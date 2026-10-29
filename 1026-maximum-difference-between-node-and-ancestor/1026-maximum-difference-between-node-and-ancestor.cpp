class Solution {
public:
    int ans = 0;

    void dfs(TreeNode* root, int mn, int mx) {
        if (!root) return;

        mn = min(mn, root->val);
        mx = max(mx, root->val);

        ans = max(ans, mx - mn);

        dfs(root->left, mn, mx);
        dfs(root->right, mn, mx);
    }

    int maxAncestorDiff(TreeNode* root) {
        dfs(root, root->val, root->val);
        return ans;
    }
};