class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0, write = 0, n = chars.size();
        while (i < n) {
            char c = chars[i];
            int j = i;
            while (j < n && chars[j] == c) j++;
            chars[write++] = c;
            int cnt = j - i;
            if (cnt > 1)
                for (char d : to_string(cnt)) chars[write++] = d;
            i = j;
        }
        return write;
    }
};