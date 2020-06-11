/*
Write a program to find the n-th ugly number.
Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 
Example:

Input: n = 10
Output: 12
Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
Note:  
1 is typically treated as an ugly number.
n does not exceed 1690.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ugly-number-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    int nthUglyNumber(int n) {
      vector<int> v(n, 0);
      v[0] = 1;
      int i_2 = 0;
      int i_3 = 0;
      int i_5 = 0;
      for (int j = 1; j < n; ++j) {
        v[j] = min(v[i_2] * 2, min(v[i_3] * 3, v[i_5] * 5));
        while (v[i_2] * 2 <= v[j]) {
          i_2++;
        }
        
        while (v[i_3] * 3 <= v[j]) {
          i_3++;
        }
        
        while (v[i_5] * 5 <= v[j]) {
          i_5++;
        }
      }
      return v[n-1];
    }
};