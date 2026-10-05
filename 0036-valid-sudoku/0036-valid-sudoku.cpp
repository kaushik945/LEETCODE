class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            vector<int> freq(10);
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.')
                    freq[board[i][j] - '0']++;
            }
            for (int j = 0; j <= 9; j++) {
                if (freq[j] > 1)
                    return false;
            }
        }
        for (int i = 0; i < 9; i++) {
            vector<int> freq(10);
            for (int j = 0; j < 9; j++) {
                if (board[j][i] != '.')
                    freq[board[j][i] - '0']++;
            }
            for (int j = 0; j <= 9; j++) {
                if (freq[j] > 1)
                    return false;
            }
        }
        int start_r = 0, start_c = 0;
        for (int start_r = 0; start_r < 9; start_r += 3) {
            for (int start_c = 0; start_c < 9; start_c += 3) {
                vector<int> freq(10);
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        if (board[i+start_r][j+start_c] != '.')
                            freq[board[i+start_r][j+start_c] - '0']++;
                    }
                }
                for (int j = 0; j <= 9; j++) {
                    if (freq[j] > 1)
                        return false;
                }
            }
        }
        return true;
    }
};