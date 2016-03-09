/*Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?

Credits:
Special thanks to @pbrother for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

Hide Tags Dynamic Programming Binary Search
Show Similar Problems
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        if(len == 0)
            return 0;
        vector<int> helper(len);//helper[j] 表示从开头到第j个字符处，最长递增长度
        helper[0] = 1;
        int resultMax = 0;
        for(int i = 0; i <= len - 1; i++) {//查找i位之前的最长递增长度
            int max = 0;
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i] && helper[j] > max)
                    max = helper[j];
            }
            helper[i] = max + 1;
            if(helper[i] > resultMax)
                resultMax = helper[i];
        }
        return resultMax;        
    }
};