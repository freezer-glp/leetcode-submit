/*A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> v(m, vector<int>(n));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0)
                    v[i][j] = 1;
                else if(i == 0) {
                    v[i][j] = v[i][j - 1];
                }else if(j == 0) {
                    v[i][j] = v[i - 1][j];
                }else
                    v[i][j] = v[i - 1][j] + v[i][j - 1];
            }
        }
        // cout<<v[m - 1][n - 1]<<endl;
        return v[m - 1][n - 1];
    }
};