class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty,
                            vector<int>& profit,
                            vector<int>& worker) {
        vector<pair<int, int>> jobs;

        for (int i = 0; i < difficulty.size(); ++i) {
            jobs.push_back({difficulty[i], profit[i]});
        }

        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());

        int total = 0;
        int bestProfit = 0;
        int job = 0;

        for (int ability : worker) {
            while (job < jobs.size() && jobs[job].first <= ability) {
                bestProfit = max(bestProfit, jobs[job].second);
                ++job;
            }
            total += bestProfit;
        }

        return total;
    }
};