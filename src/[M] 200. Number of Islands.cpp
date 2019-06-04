/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
Example 2:

Input:
11000
11000
00100
00011

Output: 3
*/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
      int m = grid.size();
      if (!m) return 0;
      int n = grid[0].size();
      int count = 0;
      int** map = new int*[m];
      for (int j=0; j<m; ++j) {
        map[j] = new int[n];
      }
      for (int i = 0; i < m; ++i)
        for (int j=0; j<n; ++j) {
          map[i][j] = grid[i][j]=='1'? -1: 0;
        }
      
      for (int i = 0; i < m; ++i){
        for (int j=0; j<n; ++j) {
          if (map[i][j] >= 0) {
            continue;
          }
          if (map[i][j] == -1) {
            count++;
            dfs(map,m, n, i, j, count);
          }
        }
      }
      return count;
   }
   
  void dfs(int** map, int m, int n, int i, int j, int count) {
    if (i>= 0 && i < m && j>=0 && j < n && map[i][j] == -1) {
      map[i][j] = count;
      dfs(map,m, n, i, j+1, count);
      dfs(map, m, n, i+1, j, count);
      dfs(map,m, n, i, j-1, count);
      dfs(map, m, n, i-1, j, count);
    }
  }
};