/*
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Note:

All numbers will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Example 2:

Input: k = 3, n = 9
Output: [[1,2,6], [1,3,5], [2,3,4]]
*/

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
      vector<vector<int>> res;
      vector<int> tmp;
      bt(k, n, tmp, res);
      return res;
    }
    
    void bt(int k, int n, vector<int>& tmp, vector<vector<int>>& res) {
      if (tmp.size() == k && n != 0) return;
      if (tmp.size() == k && n == 0) {
        res.push_back(tmp);
        return;
      }
      int i = tmp.empty()? 1: tmp.back() + 1;
      for (; i <= 9; ++i) {
        if (i <= n) {
          tmp.push_back(i);
          bt(k, n - i, tmp, res);
          tmp.pop_back();
        } else {
          break;
        }
      }
    }
};