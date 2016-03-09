/*Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Subscribe to see which companies asked this question

Hide Tags Array Dynamic Programming
Show Similar Problems
*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() ==  0)
            return 0;
            
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> res(m, vector<int>(n, grid[0][0]));
        for(int i = 0; i <= m - 1; i++) {
            for(int j = 0; j <= n - 1; j++) {
                if(i == 0 && j == 0) {
                    res[i][j] = grid[i][j];
                }else {
                    int p1, p2;
                    if(i - 1 >= 0)
                        p1 = res[i - 1][j];
                    else
                        p1 = 0x7FFFFFFF;//设置为最大整形
                    if(j - 1 >= 0)
                        p2 = res[i][j - 1];
                    else
                        p2 = 0x7FFFFFFF;
                    int mintmp = p1 < p2 ? p1 : p2;
                    res[i][j] = mintmp + grid[i][j];
                }                    
            }
        }
        return res[m - 1][n - 1];
            
    }
    
};