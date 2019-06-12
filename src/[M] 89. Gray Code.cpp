/*
The gray code is a binary numeral system where two successive values differ in only one bit.
Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.
Example 1:
Input: 2
Output: [0,1,3,2]
Explanation:
00 - 0
01 - 1
11 - 3
10 - 2

For a given n, a gray code sequence may not be uniquely defined.
For example, [0,2,3,1] is also a valid gray code sequence.

00 - 0
10 - 2
11 - 3
01 - 1
Example 2:

Input: 0
Output: [0]
Explanation: We define the gray code sequence to begin with 0.
             A gray code sequence of n has size = 2n, which for n = 0 the size is 20 = 1.
             Therefore, for n = 0 the gray code sequence is [0].

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/gray-code
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    vector<int> grayCode(int n) {
      if (n == 0) {
        vector<int> res(1, 0);
        return res;
      } 
      if (n == 1) {
        vector<int> res = {0, 1};
        return res;
      }
      vector<int> res = grayCode(n-1);
      int len = res.size();
      for (int i = len-1; i>=0; --i) {
        res.push_back(res[i] ^ (1<<(n-1)));
      }
      return res;
    }
};