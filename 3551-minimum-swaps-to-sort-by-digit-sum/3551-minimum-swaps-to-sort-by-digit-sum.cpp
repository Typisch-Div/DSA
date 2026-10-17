
class Solution {
public:
    int digitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int, int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        sort(arr.begin(), arr.end(), [&](auto a, auto b) {
            int sumA = digitSum(a.first);
            int sumB = digitSum(b.first);

            if (sumA != sumB)
                return sumA < sumB;

            return a.first < b.first;
        });

        vector<int> vis(n, 0);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i] || arr[i].second == i)
                continue;

            int j = i;
            int len = 0;

            while (!vis[j]) {
                vis[j] = 1;
                j = arr[j].second;
                len++;
            }

            ans += len - 1;
        }

        return ans;
    }
};
