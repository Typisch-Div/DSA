class Solution {
public:
    int countBinarySubstrings(string s) {
        int previousGroup = 0;
        int currentGroup = 1;
        int count = 0;

        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == s[i - 1]) {
                ++currentGroup;
            } else {
                count += min(previousGroup, currentGroup);
                previousGroup = currentGroup;
                currentGroup = 1;
            }
        }

        count += min(previousGroup, currentGroup);
        return count;
    }
};