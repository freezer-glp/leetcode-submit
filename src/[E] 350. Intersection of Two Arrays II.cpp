/*
Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/intersection-of-two-arrays-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
      vector<int> res;
      map<int, int> m;
      for (auto& i : nums1) {
        if (m.count(i) > 0) {
          m[i]++;
        } else {
          m[i] = 1;
        }
      }
      for (auto& j : nums2) {
        if (m.count(j) > 0 && m[j] > 0 ) {
          res.push_back(j);
          m[j]--;
        }
      }
      return res;
    }
};