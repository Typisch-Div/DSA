class Solution {
public:
    unordered_set<string> dict;
    unordered_map<int, vector<string>> memo;

    vector<string> solve(int start, string& s) {
        if (memo.count(start)) return memo[start];

        vector<string> ans;

        if (start == s.size()) {
            ans.push_back("");
            return ans;
        }

        for (int end = start + 1; end <= s.size(); end++) {
            string word = s.substr(start, end - start);

            if (!dict.count(word)) continue;

            vector<string> rest = solve(end, s);

            for (string sentence : rest) {
                if (sentence.empty())
                    ans.push_back(word);
                else
                    ans.push_back(word + " " + sentence);
            }
        }

        return memo[start] = ans;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        dict = unordered_set<string>(wordDict.begin(), wordDict.end());
        memo.clear();

        return solve(0, s);
    }
};