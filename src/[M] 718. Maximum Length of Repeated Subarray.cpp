/*
Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.

Example 1:

Input:
A: [1,2,3,2,1]
B: [3,2,1,4,7]
Output: 3
Explanation: 
The repeated subarray with maximum length is [3, 2, 1].

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-length-of-repeated-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
//dp新思路，用二维表示以i 结尾的结果
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
      if (A.empty() || B.empty()) {
        return 0;
      }
      int dp[1000][1000];
      int max = 0;
      for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < B.size(); ++j) {
          if (A[i] == B[j]) {
            if (i > 0 && j > 0) {
              dp[i][j] = dp[i-1][j-1] + 1;
            } else {
              dp[i][j] = 1;
            }
          } else {
            dp[i][j] = 0;
          }
          if (dp[i][j] > max) 
            max = dp[i][j];
        }
      }
      return max;
    }
};