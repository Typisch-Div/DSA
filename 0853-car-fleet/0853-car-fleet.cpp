class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> cars;
        for (int i = 0; i < position.size(); i++)
            cars.push_back({position[i], (double)(target - position[i]) / speed[i]});
        sort(cars.rbegin(), cars.rend());
        int ans = 0;
        double last = 0;
        for (auto& car : cars) {
            if (car.second > last) {
                ans++;
                last = car.second;
            }
        }
        return ans;
    }
};