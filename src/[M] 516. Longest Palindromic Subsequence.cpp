/*
Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.

Example 1:
Input:

"bbbab"
Output:
4
One possible longest palindromic subsequence is "bbbb".
Example 2:
Input:

"cbbd"
Output:
2
One possible longest palindromic subsequence is "bb".
*/
class Solution {
public:
    int longestPalindromeSubseq(string s) {
      if (s.empty()) return 0;
      int n = s.size();
      int dp[n][n];
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; j++)
          dp[i][j] = 0;
      for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
        for (int j = i-1; j >= 0; --j) {
          if (s[i] == s[j]) {
            dp[j][i] = dp[j+1][i-1] + 2;
          } else {
            dp[j][i] = std::max(dp[j][i-1], dp[j+1][i]);
          }
        }
      }
      return dp[0][n-1];
    }
};