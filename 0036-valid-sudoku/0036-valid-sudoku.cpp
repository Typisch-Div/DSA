class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& b) {
        bool row[9][9] = {}, col[9][9] = {}, box[9][9] = {};
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (b[i][j] == '.') continue;
                int x = b[i][j] - '1';
                int k = (i / 3) * 3 + j / 3;
                if (row[i][x] || col[j][x] || box[k][x]) return false;
                row[i][x] = col[j][x] = box[k][x] = true;
            }
        }
        return true;
    }
};