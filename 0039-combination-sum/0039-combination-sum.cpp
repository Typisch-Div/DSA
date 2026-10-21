class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int>& c, int target, int start, vector<int>& path) {
        if (target == 0) {
            ans.push_back(path);
            return;
        }
        for (int i = start; i < c.size(); i++) {
            if (c[i] > target) continue;
            path.push_back(c[i]);
            dfs(c, target - c[i], i, path);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& c, int target) {
        vector<int> path;
        dfs(c, target, 0, path);
        return ans;
    }
};
