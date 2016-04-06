/*
Note: This is an extension of House Robber.

After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

Hide Tags Dynamic Programming
Show Similar Problems

*/

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];
        return max(rob(nums, 0, nums.size() - 2), rob(nums, 1, nums.size() - 1));//针对是否rob 0号房子，将环拆分成链，好厉害！
         
    }
    int rob(vector<int>& nums, int lo, int high) {
        int include = 0; int exclude = 0;
        for(int j = lo; j <= high; j++) {
            cout<<j<<endl;
            int i = include, e = exclude;
            include = e + nums[j];
            exclude = max(i, e);
        }
        return max(include, exclude);
    }
};