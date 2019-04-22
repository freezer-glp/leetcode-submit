/*
Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)

Example 1:

[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.
Example 2:

[[0,0,0,0,0,0,0,0]]
Given the above grid, return 0.

*/
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
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
          map[i][j] = grid[i][j]==1? -1: 0;
        }
      
      int max = 0;
      for (int i = 0; i < m; ++i){
        for (int j=0; j<n; ++j) {
          if (map[i][j] >= 0) {
            continue;
          }
          if (map[i][j] == -1) {
            max=std::max(max,dfs(map,m, n, i, j));
          }
        }
      }
      return max;
    }
  
   int dfs(int** map, int m, int n, int i, int j) {
    if (i>= 0 && i < m && j>=0 && j < n && map[i][j] == -1) {
      map[i][j] = 1;
      int max = 1 +
      dfs(map,m, n, i, j+1)+
      dfs(map, m, n, i+1, j)+
      dfs(map,m, n, i, j-1)+
      dfs(map, m, n, i-1, j);
      //cout <<"i:"<<i<<" j:"<<j<<" max:"<<max<<endl;
      return max;
    }
    return 0;
  }
};