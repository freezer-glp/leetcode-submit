/*
Given an array of integers A with even length, return true if and only if it is possible to reorder it such that A[2 * i + 1] = 2 * A[2 * i] for every 0 <= i < len(A) / 2.

 

Example 1:

Input: [3,1,3,6]
Output: false
Example 2:

Input: [2,1,2,6]
Output: false
Example 3:

Input: [4,-2,2,-4]
Output: true
Explanation: We can take two groups, [-2,-4] and [2,4] to form [-2,-4,2,4] or [2,4,-2,-4].
Example 4:

Input: [1,2,4,16,8,4]
Output: false

*/
class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
      unordered_map<int, int> m;
      sort(A.begin(), A.end());
      for (auto i : A) {
        if (i % 2 == 0) {
          auto it = i < 0? m.find(i * 2):m.find(i / 2);
          if (it != m.end()) {
            --it->second;
            if (it->second == 0) {
              m.erase(it);
            }
            continue;
          }
        } else {
          auto it = m.find(i * 2);
          if (it != m.end()) {
            --it->second;
            if (it->second == 0) {
              m.erase(it);
            }
            continue;
          }
        }
        auto it = m.find(i);
        if (it != m.end()) {
          ++it->second;
        } else {
          m[i] = 1;
        }
      }
      return m.size() == 0;
    }
};