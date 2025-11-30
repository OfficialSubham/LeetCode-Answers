class Solution {
public:

    bool exists(vector<vector<char>> &board, string word, int idx, int i, int j) {
        if(idx == word.size()) return true;
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[idx] || board[i][j] == '#') return false;
        int up = i - 1;
        int down = i + 1;
        int left = j - 1;
        int right = j + 1;
        board[i][j] = '#';
        bool res = (exists(board, word, idx+1, up, j) || exists(board, word, idx+1, down, j) || exists(board, word, idx+1, i, left) || exists(board, word, idx+1, i, right));
        board[i][j] = word[idx];
        return res;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        if(row == 0) return false;
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(word[0] == board[i][j]) {
                    if(exists(board, word, 0, i, j)) return true;
                }
            }
        }
        return false;
    }
};