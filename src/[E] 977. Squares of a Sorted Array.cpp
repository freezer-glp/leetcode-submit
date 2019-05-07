/*
Given an array of integers A sorted in non-decreasing order, return an array of the squares of each number, also in sorted non-decreasing order.
Example 1:

Input: [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Example 2:

Input: [-7,-3,2,3,11]
Output: [4,9,9,49,121]
*/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
      vector<int> res;
      if (A.empty()) return res;
      int left = -1;
      int right = 0;
      int i = 0;
      for (; i < A.size(); ++i) {
        if (A[i] >= 0) {
          break;
        }
      }
      left = i - 1;
      right = i;
      while(left >= 0 && right < A.size()) {
        if (abs(A[left]) < A[right]) {
          res.push_back(A[left] * A[left]);
          left--;
        } else {
          res.push_back(A[right] * A[right]);
          right++;
        }
      }
      if (left < 0) {
        while(right < A.size()) {
          res.push_back(A[right] * A[right]);
          right++;
        }
      } else if (right >= A.size()) {
        while (left >= 0) {
          res.push_back(A[left] * A[left]);
          left--;
        }
      }
      return res;
    }
};
