/*
Let's call any (contiguous) subarray B (of A) a mountain if the following properties hold:

B.length >= 3
There exists some 0 < i < B.length - 1 such that B[0] < B[1] < ... B[i-1] < B[i] > B[i+1] > ... > B[B.length - 1]
(Note that B could be any subarray of A, including the entire array A.)

Given an array A of integers, return the length of the longest mountain. 

Return 0 if there is no mountain.

Example 1:

Input: [2,1,4,7,3,2,5]
Output: 5
Explanation: The largest mountain is [1,4,7,3,2] which has length 5.
Example 2:

Input: [2,2,2]
Output: 0
Explanation: There is no mountain.
*/
class Solution {
public:
    int longestMountain(vector<int>& A) {
      int n = A.size();
      if (!n) return 0;
      int max = 0;
      for (int i = 0; i < n;) {
        int tmp = 0;
        if (i + 1 < n && A[i] >= A[i+1]) {
          i++;
          continue;
        }
        if (i == n - 1) break;
        int j = i;
        while (j + 1 < n && A[j] < A[j+1]) j++;
        if (j == n - 1) break;
        if (j < n) {
          tmp += (j - i + 1);
          int k = j;
          while(k+1 < n && A[k] > A[k+1]) k++;
          if (k == j) {
            i = k;
            continue;
          }
          if (k < n) tmp += (k - j);
          else tmp += (k - j -1);
          max = std::max(max, tmp);
          i = k;
        } else 
          break;
      }
      return max;
    }
};