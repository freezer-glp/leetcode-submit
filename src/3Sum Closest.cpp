/*Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
Subscribe to see which companies asked this question

Hide Tags Array Two Pointers
Show Similar Problems
*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        if(len < 3)
            return 0;
        int res;
        int dis = INT_MAX;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < len - 2; i++) {
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            int j = i + 1;
            int k = len -1;
            while(j < k) {
                int tmpSum = nums[i] + nums[j] + nums[k];
                if(abs(tmpSum - target) < dis) {
                    res = tmpSum;
                    dis = abs(tmpSum - target);
                }
                //争取向target靠拢
                if(tmpSum > target)
                    k--;
                else if(tmpSum < target)
                    j++;
                else {
                    k--;
                    j++;
                }
                    
            }
        }
        return res;
    }
};