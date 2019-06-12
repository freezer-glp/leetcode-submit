/*
Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:

Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
 

Example 2:

Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindromic-substrings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    int countSubstrings(string s) {
      if (s.empty()) return 0;
      int len = s.size();
      int dp[len][len];
      for (int i = 0; i < len; ++i)
        for (int j = 0; j < len; ++j)
          dp[i][j] = 0;
      int sum = 0;
      for (int i = 0; i < len; ++i) {
        sum++;
        dp[i][i] = 1;
        if (i+1 < len && s[i] == s[i+1]) {
          dp[i][i+1] = 1;
          sum++;
        }
        if (i + 2 < len && s[i] == s[i+2]) {
          sum++;
          dp[i][i+2] = 1;
        }
      }
      
      for (int l = 3; l < len; ++l) {
        for (int i = 0; i < len - l; ++i) {
          if (s[i] == s[i+l] && dp[i+1][i+l-1] == 1) {
            sum++;
            dp[i][i+l] = 1;
          }
        }
      }
      return sum;
    }
};