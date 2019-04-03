/*Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

Range Sum Query 2D
The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.

Example:
Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12*/
class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
      vector<vector<int>>& mm = matrix;  
      m = mm.size();
      if (m == 0) {
        n = 0;
        return ;
      }
      n = mm[0].size();
      sum.resize(m);
      for (int i = 0; i < m; ++i) {
        sum[i].resize(n);
      }
      
      sum[0][0] = mm[0][0];
      for (int i = 1; i < m; ++i) {
        sum[i][0] = sum[i - 1][0] + mm[i][0];
      }
      for (int i = 1; i < n; ++i) {
        sum[0][i] = sum[0][i - 1] + mm[0][i];
      }
      for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
          sum[i][j] = mm[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
      }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
      if (!m && !n) return 0;
      int s1 = sum[row2][col2];
      int s2 = (row1 >= 1)?sum[row1 - 1][col2]:0;
      int s3 = (col1 >= 1)?sum[row2][col1 - 1]:0;
      int s4 = ((row1>=1) && (col1>=1))?sum[row1-1][col1 - 1]:0;
      return  s1 - s2 - s3 + s4;
    }
private:
  vector<vector<int> > sum;
  int m;
  int n;
  
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */