class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void solve(int start, int k, int target) {
        if (path.size() == k) {
            if (target == 0)
                ans.push_back(path);
            return;
        }

        for (int i = start; i <= 9; i++) {
            if (i > target) break;

            path.push_back(i);
            solve(i + 1, k, target - i);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        solve(1, k, n);
        return ans;
    }
};