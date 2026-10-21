class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> first;
        first[0] = -1;

        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum = (sum + nums[i]) % k;

            if (first.count(sum)) {
                if (i - first[sum] >= 2)
                    return true;
            } else {
                first[sum] = i;
            }
        }

        return false;
    }
};