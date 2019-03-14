/*Given an input string, reverse the string word by word.

 

Example 1:

Input: "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: "  hello world!  "
Output: "world! hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.*/

class Solution {
public:
    string reverseWords(string s) {
      for (int i = 0; i < s.size(); ++i) {
        if (s[i] == ' ') {
          if (i < s.size() - 1) {
            if (s[i + 1] == ' ') {
              s.erase(i + 1, 1);
              i--;
            }
          }
        }
      }
      int n = s.size();
      int i = 0;
      int j = n - 1;
      
      while (s[i] == ' ') i++;
      int left = i;
      
      while (s[j] == ' ') --j;
      int right = j;
      
      while (i < j) {
        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        i++;
        j--;
      }
      int ii = left;
      int jj = ii;
      while (jj < right) {
        while (s[jj] != ' ' && jj <= right) {
          jj++;
        }
        int l = ii;
        int r = jj - 1;
        while (l < r) {
          char tmp = s[l];
          s[l] = s[r];
          s[r] = tmp;
          l++;
          r--;
        }
        ii = ++jj;
        
      }
      return s.substr(left, right - left + 1);
    }
};