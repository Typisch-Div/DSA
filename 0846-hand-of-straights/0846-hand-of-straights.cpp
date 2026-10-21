class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize) return false;
        map<int, int> mp;
        for (int x : hand) mp[x]++;
        for (auto& p : mp) {
            int x = p.first, cnt = p.second;
            if (cnt == 0) continue;
            for (int j = 0; j < groupSize; j++) {
                if (mp[x + j] < cnt) return false;
                mp[x + j] -= cnt;
            }
        }
        return true;
    }
};