class Solution {
public:
    vector<string> ans;

    void dfs(string& s, int start, int parts, string cur) {
        if (parts == 4 && start == s.size()) {
            cur.pop_back();
            ans.push_back(cur);
            return;
        }

        if (parts == 4 || start == s.size())
            return;

        for (int len = 1; len <= 3 && start + len <= s.size(); len++) {
            string part = s.substr(start, len);

            if (len > 1 && part[0] == '0')
                break;

            if (stoi(part) > 255)
                break;

            dfs(s, start + len, parts + 1, cur + part + ".");
        }
    }

    vector<string> restoreIpAddresses(string s) {
        ans.clear();
        dfs(s, 0, 0, "");
        return ans;
    }
};