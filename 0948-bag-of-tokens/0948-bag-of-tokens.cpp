class Solution {
public:
    int bagOfTokensScore(vector<int>& token, int power) {
        int i = 0;
        int j = token.size() - 1;
        if (j == 0)
            return token[0] <= power ? 1 : 0;
        int ans = 0;
        int score = 0;
        sort(token.begin(), token.end());
        while (i <= j) {
            if (token[i] <= power) {
                power -= token[i++];
                score++;
                ans = max(ans, score);
            } else if (score > 0 && i < j) {
                power += token[j--];
                score--;
            } else
                break;
        }
        return ans;
    }
};