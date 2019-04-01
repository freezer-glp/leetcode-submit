/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
      vector<int> res;
      int m = matrix.size();
      if (m == 0) { return res; }
      int n = matrix[0].size();
      int m0 = 0, n0 = 0;
      while (m > 0 && n > 0) {
        if (m == 1 && n == 1) { 
          res.push_back(matrix[m0][n0]); 
          return res;
        }
        if (n > 1) {
          print_row(matrix, m, n, m0, n0, true, res);
        }
        print_col(matrix, m, n, m0, n0, true, res);
        
        if (m > 1) {
          print_row(matrix, m, n, m0, n0, false, res);
        }
        if (n > 1 && m > 1) {
          print_col(matrix, m, n, m0, n0, false, res);
        }
        m -= 2;
        n -= 2;
        m0++;
        n0++;
      }
      return res;
    }
    
    void print_row(vector<vector<int>>& matrix, int m, int n, int m0, int n0, bool left,
                  vector<int>& res) {
      int ltop = n0 + n - 1;
      if (left) {
        for (int i = n0; i < ltop; ++i) {
          cout<< "i:"<<i<<endl;
          res.push_back(matrix[m0][i]);
        }
      } else {
        if (ltop == n0) n0 -= 1;
        for (int i = ltop; i > n0; --i) {
          res.push_back(matrix[m0 + m - 1][i]);
        }
      }
    }
  
    void print_col(vector<vector<int>>& matrix, int m, int n, int m0, int n0, bool down, vector<int>& res) {
      int mtop = m0 + m -1;
      if (mtop == m0) mtop += 1;
      if (down) {
        for (int i = m0; i < mtop ; ++i) {
          res.push_back(matrix[i][n0 + n - 1]);
        }
      } else {
        for (int i = mtop ; i > m0; --i) {
          res.push_back(matrix[i][n0]);
        }
      }
    }
};