/*
Given a sorted integer array without duplicates, return the summary of its ranges.

Example 1:

Input:  [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: 0,1,2 form a continuous range; 4,5 form a continuous range.
Example 2:

Input:  [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
Explanation: 2,3,4 form a continuous range; 8,9 form a continuous range.
*/
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
      vector<string> res;
      if (nums.size() == 0) { return res; }
      int min = nums[0];
      int max = min;
      for (int i = 0; i < nums.size(); ++i) {
        int cur = nums[i];
        // cout << "cur:"<<cur<<" min:"<<min<<" max:"<<max <<endl;
        if (cur > max && cur != max + 1) {
          if (min == max) {
            res.push_back(to_string(min));
          } else {
            res.push_back(to_string(min) + "->" + to_string(max));
          }
          min = cur;
          max = min;
        } else {
          max = cur;
        }
      }
      if (min == max) {
        res.push_back(to_string(min));
      } else {
        res.push_back(to_string(min) + "->" + to_string(max));
      }
      
      return res;
    }
};