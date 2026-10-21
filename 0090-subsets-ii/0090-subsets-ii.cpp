class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& nums, int start, vector<int>& cur) {
        ans.push_back(cur);

        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) continue;

            cur.push_back(nums[i]);
            solve(nums, i + 1, cur);
            cur.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> cur;
        solve(nums, 0, cur);
        return ans;
    }
};