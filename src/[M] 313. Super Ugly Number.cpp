/*
Write a program to find the nth super ugly number.
Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k.
Example:
Input: n = 12, primes = [2,7,13,19]
Output: 32 
Explanation: [1,2,4,7,8,13,14,16,19,26,28,32] is the sequence of the first 12 
             super ugly numbers given primes = [2,7,13,19] of size 4.
Note:

1 is a super ugly number for any given primes.
The given numbers in primes are in ascending order.
0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
The nth super ugly number is guaranteed to fit in a 32-bit signed integer.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/super-ugly-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
      vector<int> v(n, 0);
      v[0] = 1;
      int p_size = primes.size();
      vector<int> p_idx(p_size, 0); // 存当前因子，可用的下标
      for (int i = 1; i < n; ++i) {
        int min = INT_MAX;
        for (int j = 0; j < p_size; ++j) {
           min = std::min(min, v[p_idx[j]] * primes[j]); // 多组值取最小
        }
        v[i] = min;
        for (int j = 0; j < p_size; ++j) {
          while (v[p_idx[j]] * primes[j] <= v[i]) { // 试探每个因子，可能的最大位置
            p_idx[j]++;
          }
        }
      }
      return v[n-1];
    }
};