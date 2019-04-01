/*Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Note: The algorithm should run in linear time and in O(1) space.

Example 1:

Input: [3,2,3]
Output: [3]
Example 2:

Input: [1,1,1,3,3,2,2,2]
Output: [1,2]*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
      vector<int> res;
      int x = 0, y = 0, cx = 0, cy = 0;
      /*
      摩尔投票法。该算法用于1/2情况，它说：“在任何数组中，出现次数大于该数组长度一半的值只能有一个。”
那么，改进一下用于1/3。可以着么说：“在任何数组中，出现次数大于该数组长度1/3的值最多只有两个。”
      */
      for (auto& num : nums) {
        if (num == x) cx++;
        else if (num == y) cy++;
        else if (cx == 0) { x = num; cx = 1; }
        else if (cy == 0) { y = num; cy = 1; }
        else { cx--; cy--; }
      }
      
      cx = 0;
      cy = 0;
      for (auto& num : nums) {
        if (num == x) cx++;
        else if (num == y) cy++;
      }
      
      if (cx > nums.size() / 3) res.push_back(x);
      if (cy > nums.size() / 3) res.push_back(y);
      return res;
    }
};