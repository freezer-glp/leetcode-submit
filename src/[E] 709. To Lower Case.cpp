/*Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.

 

Example 1:

Input: "Hello"
Output: "hello"
Example 2:

Input: "here"
Output: "here"
Example 3:

Input: "LOVELY"
Output: "lovely"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/to-lower-case
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    string toLowerCase(string str) {
      if (str.empty()) return str;
      for (int i = 0; i < str.size(); ++i) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
          str[i] = 'a' + (str[i]-'A');
        }
      }
      return str;
    }
};