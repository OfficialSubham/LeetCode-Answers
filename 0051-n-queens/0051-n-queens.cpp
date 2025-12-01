class Solution {
public:
    
    void solve(vector<vector<string>> &ans, vector<string> &board, vector<int> &lowerDiagonal, vector<int> &upperDiagonal, vector<int> &leftRow, int col, int n) {
        if(col == n) {
            ans.push_back(board);
            return;
        }

        for(int row = 0; row < n; row++) {
            if(!upperDiagonal[(n - 1) + (col - row)] && !lowerDiagonal[row + col] && !leftRow[row]) {
                upperDiagonal[(n - 1) + (col - row)] = 1;
                lowerDiagonal[row + col] = 1;
                leftRow[row] = 1;
                board[row][col] = 'Q';
                solve(ans, board, lowerDiagonal, upperDiagonal, leftRow, col + 1, n);
                upperDiagonal[(n - 1) + (col - row)] = 0;
                lowerDiagonal[row + col] = 0;
                leftRow[row] = 0;
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for(int i = 0; i < n; i++) {
            board[i] = s;
        }
        vector<int> lowerDiagonal(2*n - 1, 0);
        vector<int> upperDiagonal(2*n - 1, 0);
        vector<int> leftRow(n, 0);

        solve(ans, board, lowerDiagonal, upperDiagonal, leftRow, 0, n);
        return ans;
    }
};