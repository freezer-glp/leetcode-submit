/*
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example:

Input: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4

*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
      int m = matrix.size();
      if (m == 0) { return 0; }
      int n = matrix[0].size();
      vector<vector<int>> mm(m,vector<int>(n,0));
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          mm[i][j] = (matrix[i][j] - '0');
        }
      }
      int max = 0;
      
      int Len = std::min(m, n);
      int*** dp = new int**[m];
      for (int i = 0; i < m; ++i) {
        dp[i] = new int*[n];
        for (int j = 0; j < n; ++j) {
          dp[i][j] = new int[Len+1];
        }
      }
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          dp[i][j][1] = mm[i][j];
          if ((max == 0) && (mm[i][j] == 1)) { max = 1; }
        }
      }
      
      for (int len = 2; len <= Len; ++len) {
        for (int i = 0; i < m; ++i) {
          for (int j = 0; j < n; ++j) {
            if ((mm[i][j] == 1) && ((i + len - 1) < m) && ((j + len - 1) < n)&&
              ((i+1) < m) && ((j+1)<n) && (dp[i+1][j+1][len-1] == 1)) {
              bool flag = true;
              for (int p = i + 1; p < m && p < (i + len); ++p) {
                if ((mm[p][j] == 0 )|| (mm[p][j+len-1]==0)) {
                  dp[i][j][len] = 0;
                  flag = false;
                  break;
                }
              }
              if (!flag) continue;
              for (int p = j + 1; p < n && p < (j + len); ++p) {
                if ((mm[i][p] == 0) || (mm[i+len-1][p] == 0)) {
                  dp[i][j][len] = 0;
                  flag = false;
                  break;
                }
              }
              if (!flag) continue;
              dp[i][j][len] = 1;
              max = std::max(max, len);
            } else {
              dp[i][j][len] = 0;
            }
          }
        }
      }
      
      return max * max;
    }
};