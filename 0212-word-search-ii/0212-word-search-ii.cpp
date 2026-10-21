class Solution {
    struct Node {
        Node* next[26] = {};
        string word = "";
    };
    Node* root = new Node();
    void add(string& w) {
        Node* p = root;
        for (char c : w) {
            int i = c - 'a';
            if (!p->next[i]) p->next[i] = new Node();
            p = p->next[i];
        }
        p->word = w;
    }
    void dfs(vector<vector<char>>& b, int i, int j, Node* p,
             vector<string>& ans) {
        char c = b[i][j];
        if (c == '#' || !p->next[c - 'a']) return;
        p = p->next[c - 'a'];
        if (!p->word.empty()) {
            ans.push_back(p->word);
            p->word.clear();
        }
        b[i][j] = '#';
        int m = b.size(), n = b[0].size();
        if (i > 0) dfs(b, i - 1, j, p, ans);
        if (j > 0) dfs(b, i, j - 1, p, ans);
        if (i + 1 < m) dfs(b, i + 1, j, p, ans);
        if (j + 1 < n) dfs(b, i, j + 1, p, ans);
        b[i][j] = c;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (string& w : words) add(w);
        vector<string> ans;
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
                dfs(board, i, j, root, ans);
        return ans;
    }
};