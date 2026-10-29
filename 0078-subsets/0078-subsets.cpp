class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void solve(int i, vector<int>& nums) {
        if (i == nums.size()) {
            ans.push_back(path);
            return;
        }

        path.push_back(nums[i]);
        solve(i + 1, nums);
        path.pop_back();

        solve(i + 1, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        solve(0, nums);
        return ans;
    }
};