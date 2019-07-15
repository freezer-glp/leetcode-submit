/*
Find the length of the longest substring T of a given string (consists of lowercase letters only) such that every character in T appears no less than k times.

Example 1:

Input:
s = "aaabb", k = 3

Output:
3

The longest substring is "aaa", as 'a' is repeated 3 times.
Example 2:

Input:
s = "ababbc", k = 2

Output:
5

The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-substring-with-at-least-k-repeating-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    int longestSubstring(string s, int k) {
      if (s.size() < k || k == 0) {
        return 0;
      }
      if (k == 1) return s.size();
      return helper(s, k, 0, s.size() - 1);
    }
  
    int helper(string& s, int k, int l, int r) {
      if (r - l + 1 < k) return 0;
      map<char, int> m;
      // build map
      for (int i = l; i <= r; ++i) {
        if (m.count(s[i]) > 0) {
          m[s[i]]++;
        } else {
          m[s[i]] = 1;
        }
      }
      // 去除两端不满足的字符
      while ((r-l+1 >= k) && m[s[r]] < k) {
        r--;
      } 
      
      while ((r-l+1 >= k) && m[s[l]] < k) {
        l++;
      } 
      
      for (int i = l; i <= r; ++i) {
        if (m[s[i]] < k) {
          return std::max(helper(s,k,l,i-1), helper(s,k,i+1,r));
        }
      }
      return r-l+1;
    }
};