class Solution {
public:
    string longestNiceSubstring(string s) {
        int best = 0, start = 0;

        for (int i = 0; i < s.size(); i++) {
            int lower = 0, upper = 0;

            for (int j = i; j < s.size(); j++) {
                if (islower(s[j]))
                    lower |= 1 << (s[j] - 'a');
                else
                    upper |= 1 << (s[j] - 'A');

                if (lower == upper && j - i + 1 > best) {
                    best = j - i + 1;
                    start = i;
                }
            }
        }

        return s.substr(start, best);
    }
};