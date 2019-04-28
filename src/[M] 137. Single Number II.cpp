/*
Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,3,2]
Output: 3
Example 2:

Input: [0,1,0,1,0,1,99]
Output: 99
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
      int one = 0; int two = 0; int three;
      for (auto num : nums) {
        two |= (one & num); // 由于two要考虑，one的已有状态，和当前是否继续出现。所以要先算
        one = one ^ num;  // one就是一个0,1的二值位，在两个状态间转换
        three = (one & two);  // 当1和2都出现时，表示出现3次了，把three置1
        one = one & ~three;  // 当three为1时，需要把one , two 置0
        two = two & ~three;
      }
      return one;
    }
};