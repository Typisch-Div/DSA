class Solution {
public:
    int countAsterisks(string s) {
        int bars = 0, ans = 0;

        for (char c : s) {
            if (c == '|') bars++;
            else if (c == '*' && bars % 2 == 0) ans++;
        }

        return ans;
    }
};