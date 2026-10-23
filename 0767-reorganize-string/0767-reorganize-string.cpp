class Solution {
public:
    string reorganizeString(string s) {
        vector<int> cnt(26, 0);

        for (char c : s) cnt[c - 'a']++;

        priority_queue<pair<int, char>> pq;

        for (int i = 0; i < 26; i++) {
            if (cnt[i])
                pq.push({cnt[i], char('a' + i)});
        }

        string ans;
        pair<int, char> prev = {0, '#'};

        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            ans += cur.second;
            cur.first--;

            if (prev.first > 0)
                pq.push(prev);

            prev = cur;
        }

        return ans.size() == s.size() ? ans : "";
    }
};