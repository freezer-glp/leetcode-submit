/*Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
Subscribe to see which companies asked this question

Hide Tags Array Backtracking
Hide Similar Problems*/

class Solution {
public:
    vector<vector<int>> path;
    bool search(vector<vector<char>>& board, string word, int si, int sj, int index) {
        if(board[si][sj] != word[index])//not match this time
            return false;
        
        if(board[si][sj] == word[index] && index == word.size() - 1) //the last char of word has matched
            return true;
            
        int h = board.size();
        int l = board[0].size();
        //match 
        path[si][sj] = 1;
        int ni, nj;
        //up
        ni = si - 1;
        nj = sj;
        if(ni >= 0 && path[ni][nj] != 1 && search(board, word, ni, nj, index + 1))
            return true;
        //down
        ni = si + 1;
        nj = sj;
        if(ni < h && path[ni][nj] != 1 && search(board, word, ni, nj, index + 1))
            return true;
        //left
        ni = si;
        nj = sj - 1;
        if(nj >= 0 && path[ni][nj] != 1 && search(board, word, ni, nj, index + 1))
            return true;
        //right
        ni = si;
        nj = sj + 1;
        if(nj < l && path[ni][nj] != 1 && search(board, word, ni, nj, index + 1))
            return true;
        
        path[si][sj] = 0;//backtracking
        return false;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        //init the path
        int h = board.size();
        int l = board[0].size();
        if(h * l < word.size())
            return false;
            
        for(int i = 0; i < h; i++) {
            vector<int> tmp;
            for(int j = 0; j < l; j++) {
                tmp.push_back(0);
            }
            path.push_back(tmp);
        }
        
        bool find = false;
        for(int i = 0; i < h; i++)
            for(int j = 0; j < l; j++) {
                if(board[i][j] == word[0]) {
                    if(search(board, word, i, j, 0))
                        return true;
                    
                }
            }
        
        return false;
        
    }
};