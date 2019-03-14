/*
Given an array of integers A, find the sum of min(B), where B ranges over every (contiguous) subarray of A.

Since the answer may be large, return the answer modulo 10^9 + 7.

 

Example 1:

Input: [3,1,2,4]
Output: 17
Explanation: Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.  Sum is 17.
 

Note:

1 <= A.length <= 30000
1 <= A[i] <= 30000
*/

//  单调栈解法，n^2的dp会超时
class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
      int N = A.size();
      long long min_sum = 0;
      int modulo = (int)(pow(10, 9) +7);
      int left[N];
      int right[N];
      stack<pair<int, int>> s1, s2;
      
      for (int i = 0; i < N; ++i) {
        int count = 1;
        while (!s1.empty() && s1.top().first > A[i]) {
          count += s1.top().second;
          s1.pop();
        }
        s1.push({A[i], count});
        left[i] = count;
      }
      
      for (int i = N - 1; i >= 0; --i) {
        int count = 1;
        while (!s2.empty() && s2.top().first >= A[i]) {
          count += s2.top().second;
          s2.pop();
        }
        s2.push({A[i], count});
        right[i] = count;
      }
      
      for (int i = 0; i < N; ++i) {
        min_sum += (A[i] * left[i] * right[i]);
      }
      
      return min_sum % modulo;
    }
};