/*Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.

Subscribe to see which companies asked this question

Hide Tags Hash Table
Show Similar Problems
*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if(board.size() == 0)
            return false;
        int rowLen = board.size();
        int colLen = board[1].size();
        //检查大矩阵
        bool valid = checkRC(board, 0, rowLen - 1, 0, colLen - 1);
        if(!valid)
            return false;
        //检查九宫格
        for(int i = 0; i <= 6; i += 3)
            for(int j = 0; j <= 6; j += 3) {
                valid = checkSquare(board, i, i + 2, j, j + 2);
                if(!valid)
                    return false;
            }
            
        return true;
    }
    bool checkRC(vector<vector<char>>& board, int bRow, int tRow, int bCol, int tCol) {
        //检查每一行是否重复
        map<char, int> m;
        for(int i = bRow; i <= tRow; i++) {
            m.clear();
            for(int j = bCol; j <= tCol; j++) {
                //cout<<"char:"<<board[i][j]<<endl;
                if(board[i][j] >= '0' && board[i][j] <= '9') 
                    if(m.find(board[i][j]) == m.end()) //没有出现过该数字
                        m[board[i][j]] = 1;
                    else
                        return false;
            }
        }
        //检查每一列
        for(int j = bCol; j <= tCol; j++) {
            m.clear();
            for(int i = bRow; i <= tRow; i++) {
                if(board[i][j] >= '0' && board[i][j] <= '9') {
                   // cout<<board[i][j]<<endl;
                    if(m.find(board[i][j]) == m.end()) //没有出现过该数字
                        m[board[i][j]] = 1;
                    else
                        return false;
                }
            }
        }
        
        return true;
    }
    bool checkSquare(vector<vector<char>>& board, int bRow, int tRow, int bCol, int tCol) {
        map<char, int> m;
        for(int i = bRow; i <= tRow; i++) {
            for(int j = bCol; j <= tCol; j++) {
                if(board[i][j] >= '0' && board[i][j] <= '9') 
                    if(m.find(board[i][j]) == m.end()) //没有出现过该数字
                        m[board[i][j]] = 1;
                    else 
                        return false;
            }
        }
        return true;
    }
};