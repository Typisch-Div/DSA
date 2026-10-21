class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (!words.count(endWord)) return 0;
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        words.erase(beginWord);
        while (!q.empty()) {
            auto [s, d] = q.front();
            q.pop();
            if (s == endWord) return d;
            for (int i = 0; i < s.size(); i++) {
                char old = s[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    s[i] = c;
                    if (words.count(s)) {
                        words.erase(s);
                        q.push({s, d + 1});
                    }
                }
                s[i] = old;
            }
        }
        return 0;
    }
};