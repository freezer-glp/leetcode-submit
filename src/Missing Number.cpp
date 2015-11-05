/*Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

Hide Tags Array Math Bit Manipulation
Show Similar Problems
*/
class Solution {
public:
    int getOriginSum(int n) { // if we not lost any num
        return (1 + n) * n / 2;
    }
    int getCurSum(vector<int>& nums) {
        //now sum
        int sum = 0;
        for(int i = 0; i <= nums.size() - 1; i++) {
            sum += nums[i];
        }
        return sum;
    }
    int getMax(vector<int>& nums) {
        int m = -1;
        for(int i = 0; i <= nums.size() - 1; i++) {
            if(m < nums[i]) {
                m = nums[i];
            }
        }
        return m;
        
    }
    
    int missingNumber(vector<int>& nums) {
        int max = getMax(nums);
        if(max == nums.size() - 1) { //we miss the n
            return nums.size();
        }else if(max > nums.size() - 1) {
            //we miss one from 0 to n-1
            int originSum = getOriginSum(max);
            int curSum = getCurSum(nums);
            return originSum - curSum;
        }
    }
};