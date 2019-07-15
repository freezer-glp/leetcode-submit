/*
Given four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.

To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤ 500. All integers are in the range of -228 to 228 - 1 and the result is guaranteed to be at most 231 - 1.

Example:

Input:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]

Output:
2

Explanation:
The two tuples are:
1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/4sum-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
      int N = A.size();
      int res = 0;
      unordered_map<int, int> m;
        for (int k = 0; k <N; ++k) {
          for (int p = 0; p <N; ++p) {
            int tmp = C[k] + D[p];
            if (m.count(tmp) > 0) {
              m[tmp] += 1;
            } else {
              m[tmp] = 1;
            }
          }
        }
      
      for (int i = 0; i <N; ++i) {
        for (int j = 0; j <N; ++j) {
          int tmp = 0-A[i] - B[j];
          if (m.count(tmp) > 0) {
            res += m[tmp];
          }
        }
      }
      return res;
    }
};