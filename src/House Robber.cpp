/*You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Credits:
Special thanks to @ifanchu for adding this problem and creating all test cases. Also thanks to @ts for adding additional test cases.

Subscribe to see which companies asked this question

Hide Tags Dynamic Programming
Show Similar Problems
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if(len == 0)
            return 0;
        vector<int> best(len);
        for(int i = len - 1; i >= 0; i--) {
            if(i == len - 1 || i == len - 2)
                best[i] = nums[i];
            else {
                //rob the ith house or not
                best[i] = nums[i] + findMax(best, i + 2) > findMax(best, i + 1) ? nums[i] + findMax(best, i + 2) :  findMax(best, i + 1);
            }
        }
        return findMax(best, 0);
    }
    int findMax(vector<int>& best, int index) {
        int max = 0;
        for(int i = index; i <= best.size() - 1; i++) {
            if(best[i] > max)
                max = best[i];
        }
        return max;
    }
    
};
