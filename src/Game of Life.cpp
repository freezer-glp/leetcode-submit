/*According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state.*/
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if( board.size() == 0)
            return;
        int row = board.size(), col = board[0].size();
        for(int i = 0; i <= row - 1; i++)
            for(int j = 0; j <= col - 1; j++) {
                int neighbor = countNeighbor(board, row, col, i, j);
               // cout<<"neighbor:"<<neighbor<<endl;
                if(board[i][j] == 1 && neighbor >= 2 && neighbor <= 3)
                    board[i][j] = 3;
                if(board[i][j] == 0 && neighbor == 3)
                    board[i][j] = 2;
            }
        for(int i = 0; i <= row - 1; i++)
            for(int j = 0; j <= col - 1; j++) {
                board[i][j] >>= 1;
            }
        
    }
    int countNeighbor(vector<vector<int>>& board, int row, int col, int i, int j) {
        int neighbor = 0;
        for(int x = max(i - 1, 0); x <= min(i + 1, row - 1); x++) {
            for(int y = max(j - 1, 0); y <= min(j + 1, col - 1); y++) {
                neighbor += board[x][y] & 1;
            }
        }
        neighbor -= board[i][j] & 1;
        return neighbor;
    }
};