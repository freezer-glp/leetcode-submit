/*
Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-words-in-a-string-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    string reverseWords(string s) {
      if (s.empty()) return s;
      reverse(s, 0);
      return s;
    }
  
    void reverse(string& s, int l) {
      int i;
      for (i = l; i < s.size(); ++i) {
        if (s[i] == ' ') {
          break;
        }
      }
      // cout <<"size:"<<s.size()<<" l:"<<l<<" i:"<<i<<endl;
      if (i < s.size())
        reverse(s, i+1);
      reverse(s, l, i-1);
    }
  
    void reverse(string& s, int l, int r) {
      while (l < r) {
        swap(s[l], s[r]);
        l++;
        r--;
      }
    }
};