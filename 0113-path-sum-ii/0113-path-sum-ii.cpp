class Solution {
public:
    vector<vector<int>> ans;

    void dfs(TreeNode* root, int target, vector<int>& cur) {
        if (!root) return;

        cur.push_back(root->val);

        if (!root->left && !root->right && target == root->val)
            ans.push_back(cur);
        else {
            dfs(root->left, target - root->val, cur);
            dfs(root->right, target - root->val, cur);
        }

        cur.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> cur;
        dfs(root, targetSum, cur);
        return ans;
    }
};