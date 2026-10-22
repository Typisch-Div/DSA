class Solution {
public:
    bool isvow(char ch) {
        if (ch == 'a' || ch == 'A')
            return true;
        else if (ch == 'e' || ch == 'E')
            return true;
        else if (ch == 'i' || ch == 'I')
            return true;
        else if (ch == 'o' || ch == 'O')
            return true;
        else if (ch == 'u' || ch == 'U')
            return true;
        else
            return false;
    }
    string reverseVowels(string s) {
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            while (i < j && !isvow(s[i]))
                ++i;
            while (i < j && !isvow(s[j]))
                --j;

            if (i < j) {
                swap(s[i], s[j]);
                ++i;
                --j;
            }
        }

        return s;
    }
};