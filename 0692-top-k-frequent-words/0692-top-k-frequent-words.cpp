class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> cnt;

        for (string& w : words)
            cnt[w]++;

        vector<string> v;

        for (auto& p : cnt)
            v.push_back(p.first);

        sort(v.begin(), v.end(), [&](string& a, string& b) {
            if (cnt[a] == cnt[b])
                return a < b;

            return cnt[a] > cnt[b];
        });

        v.resize(k);
        return v;
    }
};