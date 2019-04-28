/*
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
*/
// 从边界进行深搜
class Solution {
public:
    void solve(vector<vector<char>>& board) {
      int m = board.size();
      if (!m) return;
      int n = board[0].size();
      for (int j = 0; j < n; ++j) {
        dfs(board, m, n, 0, j);
        dfs(board, m, n, m-1, j);
      }
      for (int i = 0; i < m; ++i) {
        dfs(board, m, n, i, 0);
        dfs(board, m, n, i, n-1);
      }
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          if (board[i][j] == 'O') {
            board[i][j] = 'X';
          } else if (board[i][j] == 'Z') {
            board[i][j] = 'O';
          }
        }
      }
    }
  
    void dfs(vector<vector<char>>& board, int m, int n, int i, int j) {
      if (i >= 0 && i < m && j >= 0 && j < n && (board[i][j] == 'O')) {
        board[i][j] = 'Z';
        dfs(board, m, n, i -1, j);
        dfs(board, m, n, i +1, j);
        dfs(board, m, n, i , j-1);
        dfs(board, m, n, i , j+1);
      }
    }
};