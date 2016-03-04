/*Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.

click to show more practice.

Subscribe to see which companies asked this question

Hide Tags Divide and Conquer Array Dynamic Programming
Show Similar Problems
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;
        vector<int> helper(len);
        helper[0] = nums[0];
        for(int i = 1; i <= len - 1; i++) {
            if(helper[i - 1] < 0) {
                helper[i] = nums[i];
            }else {
                helper[i] = nums[i] + helper[i - 1];
            }
        }
        int max = helper[0];
        for(int i : helper)
            if(i > max)
                max = i;
        return max;
    }
};