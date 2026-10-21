class Solution {
public:
    string sortSentence(string s) {
        stringstream ss(s);
        vector<string> words(10);
        string word;
        int n = 0;

        while (ss >> word) {
            int pos = word.back() - '0';
            word.pop_back();
            words[pos] = word;
            n++;
        }

        string ans;

        for (int i = 1; i <= n; i++) {
            if (i > 1) ans += ' ';
            ans += words[i];
        }

        return ans;
    }
};