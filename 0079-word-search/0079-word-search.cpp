
class Solution {
public:
    bool dfs(int i, int j, int k, vector<vector<char>>& board,
             string& word, int n, int m) {
        if (i < 0 || i >= n || j < 0 || j >= m)
            return false;

        if (board[i][j] != word[k])
            return false;

        k++;

        if (k == word.size())
            return true;

        char temp = board[i][j];
        board[i][j] = '#';

        bool check = dfs(i + 1, j, k, board, word, n, m) ||
                     dfs(i, j + 1, k, board, word, n, m) ||
                     dfs(i - 1, j, k, board, word, n, m) ||
                     dfs(i, j - 1, k, board, word, n, m);

        board[i][j] = temp;
        return check;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();

        if (n * m < word.size())
            return false;

        int c1 = 0, c2 = 0;
        int k = word.size();

        for (auto& row : board) {
            for (char c : row) {
                if (c == word[0])
                    c1++;
                if (c == word[k - 1])
                    c2++;
            }
        }

        if (c1 == 0 || c2 == 0)
            return false;

        if (c1 > c2)
            reverse(word.begin(), word.end());

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dfs(i, j, 0, board, word, n, m))
                    return true;
            }
        }

        return false;
    }
};