/*
Given an array A of integers, return the length of the longest arithmetic subsequence in A.
Recall that a subsequence of A is a list A[i_1], A[i_2], ..., A[i_k] with 0 <= i_1 < i_2 < ... < i_k <= A.length - 1, and that a sequence B is arithmetic if B[i+1] - B[i] are all the same value (for 0 <= i < B.length - 1).
Example 1:
Input: [3,6,9,12]
Output: 4
Explanation: 
The whole array is an arithmetic sequence with steps of length = 3.
Example 2:

Input: [9,4,7,2,10]
Output: 3
Explanation: 
The longest arithmetic subsequence is [4,7,10].
Example 3:

Input: [20,1,15,3,10,5,8]
Output: 4
Explanation: 
The longest arithmetic subsequence is [20,15,10,5].


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-arithmetic-sequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
      if (A.empty()) return 0;
      map<int, map<int, int>> dp; // 第i个数，差为gap的最大子序列长度k
      int res = 0;
      for (int i = 1; i < A.size(); ++i) {
        map<int, int> tmp;  // 第i个数的所有差的dp
        for (int j = i - 1; j >= 0; --j) {
          int gap = A[i] -A[j];  // 求差
          auto it1 = dp.find(j); // i从1开始，所以j=0时，这里查不到
          if (it1 != dp.end()) {
            auto it2 = it1->second.find(gap); // j数，在当前差时，最大子序列长度
            int last = 1;  // 如果没有出现过差gap，则默认为1
            if (it2 != it1->second.end()) {
              last = it2->second; // 上一个数，差为gap的长度
            }
            // 更新第i个数，在差为gap时的状态
            auto it3 = tmp.find(gap);
            if (it3 != tmp.end()) {
              // 之前出现过差为gap，需要取最大
              it3->second = std::max(it3->second, last + 1);
            } else {
              // 之前没出现过，直接+1就行
              tmp[gap] = last + 1;
              if (last+1 > res) res = last+1;
            }
          } else {
            // 如果是第一个数，则当前数的所有gap长度都为2
            tmp[gap] = 2;
            if (2 > res) res = 2;
          }
        }
        dp[i] = tmp; // 保存第i个数的dp
      }
      
      return res;
    }
};