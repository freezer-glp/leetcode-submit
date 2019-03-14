/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given a non-empty string containing only digits, determine the total number of ways to decode it.

Example 1:

Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).
Example 2:

Input: "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
*/
class Solution {
public:
    int numDecodings(string s) {
      int n = s.size();
      if (s.empty() || s[0] == '0') {
        return 0;
      }
      
      int dp[n];
      dp[0] = 1;
      for (int i = 1; i < n; ++i) {
        if (s[i] == '0') {
          // 0前面只有1，2符合条件
          if (s[i - 1] >= '1' && s[i -1] <= '2') {
            if (i >= 2) {
              // 相当于看成一个数，加入i-2
              dp[i] = dp[i - 2];
            } else {
              // 只能两个抱团
              dp[i] = 1;
            }
          } else {
            // 这个0无法处理
            return 0;
          }
        } else {
          // 和前一个能组合
          if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
            if (i >= 2) {
              dp[i] = dp[i-1] + dp[i-2];
            } else {
              dp[i] = dp[i - 1] + 1;
            }
            dp[i] = dp[i];
          } else {
            dp[i] = dp[i - 1];
          }
        }
      }
      return dp[n - 1];
    }
};