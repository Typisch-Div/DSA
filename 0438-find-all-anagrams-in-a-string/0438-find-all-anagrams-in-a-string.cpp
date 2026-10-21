class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if (p.size() > s.size()) return ans;
        vector<int> a(26, 0), b(26, 0);
        for (char c : p) a[c - 'a']++;
        for (int i = 0; i < p.size(); i++) b[s[i] - 'a']++;
        if (a == b) ans.push_back(0);
        for (int i = p.size(); i < s.size(); i++) {
            b[s[i] - 'a']++;
            b[s[i - p.size()] - 'a']--;
            if (a == b) ans.push_back(i - p.size() + 1);
        }
        return ans;
    }
};