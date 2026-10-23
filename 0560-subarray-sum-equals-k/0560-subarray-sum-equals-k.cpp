class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<long long, int> mpp;
        mpp[0] = 1;
        long long presum = 0;
        int cnt = 0;
        for (int num : nums) {
            presum += num;
            int needed = presum - k;
            if (mpp.count(needed))
                cnt += mpp[needed];
            mpp[presum]++;
        }
        return cnt;
    }
};